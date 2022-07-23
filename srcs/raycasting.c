/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/23 20:08:15 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_cub *cub)
{
	t_player	*player;

	cub->fov_an = 60 * (PI / 180);
	cub->col_width = 4;
	cub->no_rays = (cub->width * TILE_SIZE) / cub->col_width;
	player = init_player(cub);
	DrawCircle(player->pos.x, player->pos.y, 2, cub);
	cast_all_rays(cub, player);
	return (0);
}

void	DrawCircle(int x, int y, int r, t_cub *cub)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	for(i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		my_pixel_put(&cub->mlx.img, x + x1, y + y1, 0x00FF0000);
	}
}

int	cast_all_rays(t_cub *cub, t_player *player)
{
	int		i;

	i = 0;
	cub->ray_angle = player->rotation_angle - (cub->fov_an / 2);
	while (i < 3)
	{
		init_ray(cub);
		cast_ray(&cub->ray, player, cub, i);
	//	project_wall(cub);
		cub->ray_angle += cub->fov_an / cub->no_rays;
		i++;
	}
	return (0);
}

int	project_wall(t_cub *cub)
{
	float	wall_height;
	float	dist_pp;

	dist_pp = ((cub->width * 32) / 2) / tan(cub->fov_an);
	wall_height = (TILE_SIZE / cub->ray.distance) * dist_pp;
	printf("wall height is %f\n", wall_height);
	return (0);
}

void	init_ray(t_cub *cub)
{
	cub->ray.hit_x = 0;
	cub->ray.hit_y = 0;
	cub->ray.xstep = 0;
	cub->ray.ystep = 0;
	cub->ray.yintercept = 0;
	cub->ray.xintercept = 0;
	cub->ray.up = 0;
	cub->ray.down = 0;
	cub->ray.left = 0;
	cub->ray.right = 0;
	cub->ray.wall = 0;
	cub->ray.distance = 2147483647;
}

int	cast_ray(t_ray *ray, t_player *player, t_cub *cub, int col_id)
{
	cub->ray_angle = normalize_angle(cub->ray_angle);
	ray_direction(ray, col_id, cub->ray_angle);
	//horizontal_colis(&cub->ray, player, cub, cub->ray_angle);
	//vertical_colis(&cub->ray, player, cub, cub->ray_angle);
	return (0);
}

int	vertical_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	ray->xintercept = floorf(player->pos.x / TILE_SIZE) * TILE_SIZE;
	if (ray->right == 1)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = player->pos.y + (ray->xintercept - player->pos.x) \
	* tan(ray_angle);
	ray->yintercept = TILE_SIZE;
	if (ray->up == 1)
		ray->yintercept *= -1;
	ray->ystep = TILE_SIZE * tan(ray_angle);
	ray->xstep = TILE_SIZE;
	if ((ray->up == 1 && ray->ystep > 0) || \
	(ray->down && ray->ystep < 0))
		ray->ystep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * 32) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * 32))
	{
		//DrawCircle(ray->xintercept, ray->yintercept, 2, cub);
		if (is_wall(cub->char_map, ray->xintercept, \
		(ray->yintercept - ray->up)))
		{
			if (ray->distance > hypot((player->pos.x - ray->xintercept), \
			(player->pos.y - ray->yintercept)))
				ray->distance = hypot((player->pos.x - ray->xintercept), \
			(player->pos.y - ray->yintercept));
			ray->hit_x = ray->xintercept;
			ray->hit_y = ray->yintercept;
			break ;
		}
		else
		{
			ray->xintercept += ray->xstep;
			ray->yintercept += ray->ystep;
		}
	}
	return (0);
}

int	horizontal_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	ray->yintercept = floorf(player->pos.y / TILE_SIZE) * TILE_SIZE;
	if (ray->down == 1)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = player->pos.x + (player->pos.y - ray->yintercept) \
	/ tan(ray_angle);
	ray->yintercept = TILE_SIZE;
	if (ray->up == 1)
		ray->yintercept *= -1;
	ray->ystep = TILE_SIZE;
	ray->xstep = TILE_SIZE / tan(cub->fov_an);
	if ((ray->left == 1 && ray->xstep > 0) || \
	(ray->right && ray->xstep < 0))
		ray->xstep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * 32) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * 32))
	{
		DrawCircle(ray->xintercept, ray->yintercept, 2, cub);
		if (is_wall(cub->char_map, ray->xintercept, \
		(ray->yintercept - ray->up)))
		{
			if (ray->distance > hypot((player->pos.x - ray->xintercept), \
			(player->pos.y - ray->yintercept)))
				ray->distance = hypot((player->pos.x - ray->xintercept), \
			(player->pos.y - ray->yintercept));
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
	return (0);	
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
    if (ray_angle < 0) {
        ray_angle = TWO_PI + ray_angle;
    }
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
	flag = 0;
	while (tab[i] && flag == 0)
	{
		i++;
		j = 0;
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
	pos.x = (j * TILE_SIZE) + TILE_SIZE / 2;
	pos.y = (i * TILE_SIZE) - TILE_SIZE / 2;
	pos.dir = tab[i][j];
	return (pos);
}

t_player	*init_player(t_cub *cub)
{
	t_player *player;

	player = malloc(sizeof(player));
	player->pos = find_player(cub->char_map);
	if (player->pos.dir == 'N')
		player->rotation_angle = (3 *PI) * 0.5;
	if (player->pos.dir == 'E')
		player->rotation_angle = 0;
	if (player->pos.dir == 'S')
		player->rotation_angle = 90;
	if (player->pos.dir == 'W')
		player->rotation_angle = 180;
	return (player);
}
