/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/09 09:49:12 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_cub *cub)
{
	cub->fov_an = 60 * (PI / 180);
	cub->col_width = 3;
	cub->no_rays = WIDTH;
	cub->player = init_player(cub);
	//draw_mini_map(cub);
	cast_all_rays(cub, cub->player);
	//DrawCircle(cub->player->x, cub->player->y, 2, cub);
	return (0);
}

int	cast_all_rays(t_cub *cub, t_player *player)
{
	int		i;

	i = 0;
	cub->ray_angle = player->rotation_angle - (cub->fov_an * 0.5);
	while (i < cub->no_rays)
	{
		init_ray(cub);
		cast_ray(&cub->ray, player, cub, i);
		project_wall(cub, i);
		cub->ray_angle += cub->fov_an / cub->no_rays;
		i++;
	}
	return (0);
}

int	cast_ray(t_ray *ray, t_player *player, t_cub *cub, int col_id)
{
	(void)player;
	cub->ray_angle = normalize_angle(cub->ray_angle);
	ray_direction(ray, col_id, cub->ray_angle);
	horizontal_colis(&cub->ray, cub->player, cub, cub->ray_angle);
	vertical_colis(&cub->ray, cub->player, cub, cub->ray_angle);
	if (ray->wall_x == 1)
	{
		//ft_bresenham(player->x, player->y, ray->hit_x, ray->hit_y, cub);
	//	DrawCircle(ray->hit_x, ray->hit_y, 2, cub);
		//printf("ray angle = cub->ray_angle %f\n", cub->ray_angle);
		//printf("X  %f\nY : %f\n\n", ray->hit_x, ray->hit_y);
	}
	else if (ray->wall_y == 1)
	{
	//	ft_bresenham2(player->x, player->y, ray->hit_x, ray->hit_y, cub);
	//	DrawCircle2(ray->hit_x, ray->hit_y, 2, cub);
	//	printf("ray angle = cub->ray_angle %f\n", cub->ray_angle);
		//printf("X  %f\nY : %f\n\n", ray->hit_x, ray->hit_y);
	}
	return (0);
}

int	vertical_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	ray->xintercept = floorf(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->right == 1)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = player->y + (ray->xintercept - player->x) \
	* tan(ray_angle);
	ray->ystep = TILE_SIZE * tan(ray_angle);
	ray->xstep = TILE_SIZE;
	if (ray->left == 1)
		ray->xstep *= -1;
	if ((ray->up == 1 && ray->ystep > 0) || \
	(ray->down && ray->ystep < 0))
		ray->ystep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * TILE_SIZE) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * TILE_SIZE))
	{
		if (is_wall(cub->char_map, (ray->xintercept - ray->left), \
		ray->yintercept))
		{
			//DrawCircle2(ray->xintercept, ray->yintercept, 2, cub);
			if (ray->distance > hypot((ray->xintercept - player->x), \
			(ray->yintercept - player->y)))
			{
				ray->distance = hypot((ray->xintercept - player->x), \
			(ray->yintercept - player->y));
				ray->wall_y = 1;
				ray->wall_x = 0;
				ray->hit_x = ray->xintercept;
				ray->hit_y = ray->yintercept;
			}			
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
	ray->yintercept = floorf(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->down == 1)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = player->x + (ray->yintercept - player->y) \
	/ tan(ray_angle);
	ray->ystep = TILE_SIZE;
	ray->xstep = TILE_SIZE / tan(ray_angle);
	if (ray->up == 1)
		ray->ystep *= -1;
	if ((ray->left == 1 && ray->xstep > 0) || \
	(ray->right && ray->xstep < 0))
		ray->xstep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * TILE_SIZE) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * TILE_SIZE))
	{
		if (is_wall(cub->char_map, ray->xintercept, \
		(ray->yintercept - ray->up)))
		{
			//DrawCircle(ray->hit_x, ray->hit_y, 2, cub);
			if (ray->distance > hypot((ray->xintercept - player->x), \
			(ray->yintercept - player->y)))
			{
				ray->distance = hypot((ray->xintercept - player->x), \
			(ray->yintercept - player->y));
			ray->wall_x = 1;
			ray->wall_y = 0;
			ray->hit_x = ray->xintercept;
			ray->hit_y = ray->yintercept;
			}
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
