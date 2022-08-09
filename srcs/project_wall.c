/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:06:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/09 11:41:40 by clmurphy         ###   ########.fr       */
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
		offsetx = ((int)cub->ray.hit_y * \
		cub->text[cub->ray.w_id].w / TILE_SIZE) % cub->text[cub->ray.w_id].w;
	else
		offsetx = ((int)cub->ray.hit_x * \
		cub->text[cub->ray.w_id].w / TILE_SIZE) % cub->text[cub->ray.w_id].w;

	return (offsetx);
}

int	cast_col(int top_p, int bottom_p, t_cub *cub, int col_id, int w_height)
{
	unsigned int color;
	int	x;
	int	offset_x;
	int	offset_y;
	int	i;

	set_wall_id(cub);
	offset_x = get_xoffset(cub);
	cast_cel(top_p, bottom_p, cub, col_id);
	cast_floor(top_p, bottom_p, cub, col_id);
	x = WIDTH - (col_id * cub->col_width);
	while (top_p++ < bottom_p)
	{
		i = 0;
		offset_y = top_p + (w_height / 2) - (HEIGTH / 2);
		offset_y = offset_x * (float)cub->text[cub->ray.w_id].h;
		while (i < cub->col_width)
		{
			color = get_color(cub, cub->ray.w_id, offset_y);
			my_pixel_put(&cub->mlx.img, x + i, top_p, color);
			i++;
		}
	}
	return (0);
}

unsigned int	get_color(t_cub *cub, int id, int offset_y)
{
	unsigned int	color;
	(void)cub;
	(void)id;
	(void)offset_y;
	/*int				offset_x;
	int				calc;

	offset_x = get_xoffset(cub);
	calc = (cub->text[id].w * offset_y) \
	+ offset_x;
	color = cub->text[id].addr[calc];*/
	color = 0xFFFFFF;
	return (color);
}

int	cast_cel(int top_p, int bottom_p, t_cub *cub, int col_id)
{
	int	i;
	int	x;
	int	save;

	x = WIDTH - (col_id * cub->col_width);
	save = 0;
	(void)bottom_p;
	while (save <= top_p)
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
	save = bottom_p;
	//printf("x is %d save b = %d\n, top_p = %d\n\n", x, save, top_p);
	(void)top_p;
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
