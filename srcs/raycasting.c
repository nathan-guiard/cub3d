/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/14 17:21:23 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_cub *cub)
{
	t_ray		*ray;
	t_player	*player;

	cub->fov_an = 60 * (PI / 180);
	cub->col_width = 4;
	cub->no_rays = WIDTH / cub->col_width;
	ray = malloc(sizeof(ray) * cub->no_rays);
	player = malloc(sizeof(t_player));
	if (!player || !ray)
		ft_ray_error(cub, ray, player, "malloc error");
	init_player(cub, player);
	cast_all_rays(cub, player, ray);
	return (0);
}

int	cast_all_rays(t_cub *cub, t_player *player, t_ray *ray)
{
	int		i;

	i = 0;
	cub->ray_angle = player->rotation_angle - (cub->fov_an / 2);
	while (i < cub->no_rays)
	{
		cast_ray(ray, player, cub, i);
		cub->ray_angle += cub->fov_an;
		i++;
	}
	return (0);
}

int	cast_ray(t_ray *ray, t_player *player, t_cub *cub, int col_id)
{
	float	h_delta_x;
	float	h_delta_y;
	//float	delta_x;
	//float	delta_y;
	float	xintercept;
	float	yintercept;
	float	next_xintercept;
	float	next_yintercept;
	int		hit;

	hit = 0;
	/*calculate where ray First hits x horixzontal intercept*/
	/* take where the player is standing and divide by tile size whilst rounding it up,
	then times it agian by tile size to get the exact intersect */
	yintercept = floor(player->player_pos.y / TILE_SIZE) * TILE_SIZE;
	/* to get the x intercept you need to add x to you get the distance between both y coors
	which will give you opposite side of traingle which will alllow you to calculate the adjacent
	which is the distance between the x points */
	xintercept = player->player_pos.x + ((player->player_pos.y - yintercept) \
	/ tan(cub->ray_angle));
	/* HORIZONTAL delta */
	h_delta_x = TILE_SIZE / tan(cub->ray_angle);
	h_delta_y = TILE_SIZE;
	/* VERTICAL delta */
	//delta_x = TILE_SIZE * tan(cub->ray_angle);
	//delta_y = TILE_SIZE;
	ray[col_id].ray_angle = normalize_angle(cub->ray_angle);
	/*	ray direction to be able to calulcate next intercept */
	ray_direction(ray, col_id, cub->ray_angle);
	/* if the ray is pointing down ned to add 32 to go to next horizontal line
	as + 32 will make the line go down one */
	if (ray[col_id].down)
		yintercept += TILE_SIZE;
	if (ray[col_id].up == 1)
		yintercept *= -1;
	if (ray[col_id].left && xintercept > 0)
		xintercept *= -1;
	if (ray[col_id].right && xintercept < 0)
		xintercept *= -1;
	next_xintercept = xintercept;
	next_yintercept = yintercept;
	/*   find horisontal wall	*/
	while (next_xintercept <= WIDTH && next_yintercept <= \
	HEIGTH && next_xintercept >= 0 && next_yintercept >= 0 && hit == 0)
	{
		if (is_wall(cub->char_map, next_xintercept, next_yintercept))
		{
			hit = 1;
			ray[col_id].hit_x = next_xintercept;
			ray[col_id].hit_y = next_xintercept;
			my_pixel_put(&cub->mlx.img, next_xintercept, next_yintercept, cub->f_color);
			break ;
		}
		else
		{
			next_xintercept += h_delta_x;
			next_yintercept += h_delta_y;
		}			
	}
	return (0);
}

int	is_wall(char **tab, int	xinter, int yinter)
{
	int	i;
	int	j;

	i = floor(xinter / 32);
	j = floor(yinter / 32);
	if (tab[i][j] == '1')
		return (1);
	else
		return (0);
}

int	ray_direction(t_ray *ray, int col_id, float ray_angle)
{
	/* look at diagram of cirle to understand better note that PI = 180
	we rotate to the right so if its between 0 and 180 (PI) its in the lower half */
	if (ray_angle > 0 && ray_angle < PI)
		ray[col_id].up = 1;
	else
		ray[col_id].down = 1;
	/*90 degrees is pi divided by 2 and `270 is 3pi divided by two so this 
	is how we see if its left or right */
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
		ray[col_id].right = 1;
	else
		ray[col_id].left = 1;
	return (0);
}

float	normalize_angle(float ray_angle)
{
	// make sure that angle doesn't go over one roation
	ray_angle = remainder(ray_angle, TWO_PI);
	// if its negative angle add another rotation to make it positive
	if (ray_angle < 0)
		ray_angle = (2 * PI) + ray_angle;
	return (ray_angle);
}

t_pos	find_player(char **tab)
{
	int		i;
	int		j;
	int		flag;
	t_pos	pos;

	i = 0;
	j = 0;
	while (tab[i] && flag == 0)
	{
		i++;
		while (tab[i][j])
		{
			if (ft_isset(tab[i][j], "NSEW") == 1)
			{
				flag = 1;
				break ;
			}
			j++;
		}
	}
	pos.x = i * TILE_SIZE;
	pos.y = j * TILE_SIZE;
	pos.dir = tab[i][j];
	return (pos);
}

int	init_player(t_cub *cub, t_player *player)
{
	player->player_pos = find_player(cub->char_map);
	if (player->player_pos.dir == 'N')
		player->rotation_angle = 270;
	if (player->player_pos.dir == 'E')
		player->rotation_angle = 0;
	if (player->player_pos.dir == 'S')
		player->rotation_angle = 90;
	if (player->player_pos.dir == 'W')
		player->rotation_angle = 180;
	return (0);
}
