/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clodaghmurphy <clodaghmurphy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/20 18:56:39 by clodaghmurp      ###   ########.fr       */
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
		init_ray(cub);
		cast_ray(ray, player, cub, i);
		cub->ray_angle += cub->fov_an;
		i++;
	}
	return (0);
}

void	init_ray(t_cub *cub)
{
	cub->ray.hit_x = 0;
	cub->ray.hit_y = 0;
	cub->ray.xstep;
	cub->ray.ystep = 0;
	cub->ray.yintercept = 0;
	cub->ray.xintercept = 0;
	cub->ray.up = 0;
	cub->ray.down = 0;
	cub->ray.left = 0;
	cub->ray.right;
	cub->ray.wall;
}

int	cast_ray(t_ray *ray, t_player *player, t_cub *cub, int col_id)
{
	cub->ray_angle = normalize_angle(cub->ray_angle);
	ray_direction(ray, col_id, cub->ray_angle);
	horizontal_colis(&cub->ray, col_id, cub->ray_angle);
}

int horizontal_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	int	h_wall_hit;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;

	ray->yintercept = floorf(player->pos.y) * TILE_SIZE;
	if (ray->down == 1)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = player->pos.x (player->pos.y - ray->yintercept) \
	/ tan(ray_angle);
	ray->yintercept = TILE_SIZE;
	if (ray->up == 1)
		ray->yintercept *= -1;
	ray->xstep = TILE_SIZE / tan(cub->fov_angle);
	if(ray.left == 1 && ray->xstep > 0 || \
	ray.right && ray->xstep < 0)
		ray->xstep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * 32) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * 32))
	{
		if (is_wall(cub->char_map, ray->xintercept, (ray->yintercept - ray->up)
		{
			ray->hit_x = ray->xintercept;
			ray->hit_y = ray->yintercept;
			break ;
		}
		else
		{
			ray->xintercept += ray->xintercept;
			ray->yintercept += ray->yintercept;
		}
	}	
}

	int is_wall(char **tab, int xinter, int yinter)
{
	int	i;
	int	j;

	j = floor(xinter / 32);
	i = floor(yinter / 32);
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
		j =0;
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
