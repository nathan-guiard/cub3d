/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:06:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/08 17:23:38 by clmurphy         ###   ########.fr       */
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
	set_wall_id(cub);
	cast_col(top_p, bottom_p, cub, col_id, proj_wall_height);
	return (0);
}

void	set_wall_id(t_cub *cub)
{
	if (cub->ray.up == 1)
		cub->ray.w_id = 0;
	else if (cub->ray.down == 1)
		cub->ray.w_id = 1;
	else if (cub->ray.right == 1)
		cub->ray.w_id = 2;
	else if (cub->ray.left == 1)
		cub->ray.w_id = 3;
}
int	get_xoffset(t_cub *cub)
{
	int	offsetx;

	if (cub->ray.wall_y == 1)
		offsetx = (int)cub->ray.hit_y % TILE_SIZE;
	else
		offsetx = (int)cub->ray.hit_x % TILE_SIZE;
	return (offsetx);
}

int	cast_col(int top_p, int bottom_p, t_cub *cub, int col_id, int w_height)
{
	int	save;
	int	offset_x;
	int	offset_y;
	int	img_addr;
//	int	color;
	int	i;

	offset_x = get_xoffset(cub);
/* 	if (cub->ray.wall_x)
		color = 0xFFFFFF;
	if (cub->ray.wall_y)
		color = 0xD3D3D3; */
	//cast_cel(top_p, bottom_p, cub, col_id);
	//cast_floor(top_p, bottom_p, cub, col_id);
	while (top_p++ <= bottom_p)
	{
		offset_y = (top_p) + (w_height / 2) - (HEIGTH / 2);
		offset_y = offset_y * ((float)cub->text[cub->ray.w_id].h / w_height);
		i = 0;
		//printf("offest x %d offset y %d\n", offset_x, offset_y);
		(void)offset_x;
		(void)offset_y;
		while (i < cub->col_width)
		{
			img_addr = (bottom_p * cub->mlx.img.line_len / 4) + \
			(col_id * 4 + i);
			cub->mlx.img.addr[img_addr] = (char)0xFFFF00;
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
