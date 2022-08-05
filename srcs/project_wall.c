/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:06:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/05 13:36:57 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"   

int	project_wall(t_cub *cub, int col_id)
{
	float	proj_wall_height;
	float	wall_height;
	float	dist_pp;
	float	ray_distance;
	int		top_p;
	int		bottom_p;
	float	cost;

	cost = cos(cub->player->rotation_angle - cub->ray_angle);
	ray_distance = cub->ray.distance * cost;
	dist_pp = (WIDTH / 2) / tan(cub->fov_an / 2);
	proj_wall_height = (TILE_SIZE / ray_distance) * dist_pp;
	wall_height = (int)proj_wall_height;
	top_p = (HEIGTH / 2) - (wall_height / 2);
	if (top_p < 0)
		top_p = 0;
	bottom_p = (HEIGTH / 2) + (wall_height / 2);
	if (bottom_p > HEIGTH)
		bottom_p = HEIGTH;
	cast_col(bottom_p, top_p, cub, col_id);
	return (0);
}

int	cast_col(int top_p, int bottom_p, t_cub *cub, int	col_id)
{
	int	save;
	int	x;
	int	i;
	int	color;

	if (cub->ray.wall_x)
		color = 0xFFFFFF;
	if (cub->ray.wall_y)
		color = 0xD3D3D3;
	cast_cel(top_p, bottom_p, cub, col_id);
	cast_floor(top_p, bottom_p, cub, col_id);
	save = bottom_p;
	x = WIDTH - (col_id * cub->col_width);
	while (save <= top_p)
	{
		i = 0;
		while (i < cub->col_width)
		{
			my_pixel_put(&cub->mlx.img, x + i, save, color);
			i++;
		}
		save++;
	}
	return (0);
}

int	cast_cel(int top_p, int bottom_p, t_cub *cub, int col_id)
{
	int	i;
	int	x;
	int	save;

	x = WIDTH - (col_id * cub->col_width);
	save = 0;
	(void)top_p;
	while (save <= bottom_p)
	{
		i = 0;
		while (i < cub->width)
		{
			my_pixel_put(&cub->mlx.img, x + i, save, cub->c_color);
			i++;
		}
		save++;
	}
	return (0);
}

int	cast_floor(int top_p, int bottom_p, t_cub *cub, int col_id)
{
	int	i;
	int	x;
	int	save;

	x = WIDTH - (col_id * cub->col_width);
	save = top_p;
	//printf("x is %d save b = %d\n, top_p = %d\n\n", x, save, top_p);
	(void)bottom_p;
	while (save <= HEIGTH)
	{
		i = 0;
		while (i < cub->width)
		{
			my_pixel_put(&cub->mlx.img, x + i, save, cub->f_color);
			i++;
		}
		save++;
	}
	return (0);
}
