/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:50:28 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/10 11:03:22 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	vertical_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	float	tan_an;

	tan_an = tan(ray_angle);
	ray->xintercept = floorf(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->right == 1)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = player->y + (player->x - ray->xintercept) \
	* tan_an;
	ray->ystep = TILE_SIZE * tan_an;
	ray->xstep = TILE_SIZE;
	if (ray->left == 1)
		ray->xstep *= -1;
	if ((ray->up == 1 && ray->ystep > 0) || \
	(ray->down && ray->ystep < 0))
		ray->ystep *= -1;
	vertical_colis2(ray, player, cub);
	return (0);
}

int	vertical_colis2(t_ray *ray, t_player *player, t_cub *cub)
{
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * TILE_SIZE) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * TILE_SIZE))
	{
		if (is_wall(cub->char_map, (ray->xintercept - ray->left), \
		ray->yintercept))
		{
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
	float	tan_an;

	tan_an = tan(ray_angle);
	ray->yintercept = floorf(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->down == 1)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = player->x + (player->y - ray->yintercept) \
	/ tan_an;
	ray->ystep = TILE_SIZE;
	ray->xstep = TILE_SIZE / tan_an;
	if (ray->up == 1)
		ray->ystep *= -1;
	if ((ray->left == 1 && ray->xstep > 0) || \
	(ray->right && ray->xstep < 0))
		ray->xstep *= -1;
	horizontal_colis2(ray, player, cub);
	return (0);
}

int	horizontal_colis2(t_ray *ray, t_player *player, t_cub *cub)
{
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * TILE_SIZE) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * TILE_SIZE))
	{
		if (is_wall(cub->char_map, ray->xintercept, \
		(ray->yintercept - ray->up)))
		{
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
