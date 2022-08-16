/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:06:37 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 12:14:29 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub->ray.wall_x = 0;
	cub->ray.wall_y = 0;
	cub->ray.w_height = 0;
	cub->ray.w_id = 0;
	cub->ray.distance = 2147483647;
}

int	is_wall(char **tab, int xinter, int yinter)
{
	int	i;
	int	j;

	j = floorf(xinter / TILE_SIZE);
	i = floorf(yinter / TILE_SIZE);
	if (tab[i + 1][j] == '1')
		return (1);
	else
		return (0);
}

int	ray_direction(t_ray *ray, int col_id, float ray_angle)
{
	(void)col_id;
	if (ray_angle > 0 && ray_angle < PI)
		ray->up = 1;
	else
		ray->down = 1;
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
		ray->right = 1;
	else
		ray->left = 1;
	return (0);
}

float	normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
	{
		ray_angle = TWO_PI + ray_angle;
	}
	return (ray_angle);
}
