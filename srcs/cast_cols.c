/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_cols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:12:20 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/11 11:50:32 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

// int	cast_col(int top_p, int bottom_p, t_cub *cub, int col_id)
// {
// 	unsigned int	color;
// 	int				offset_y;
// 	int				i;

// 	int ratio;
// 	ratio = cub->ray.w_height / 64;
// 	if (ratio == 1)
// 		ratio++;
// 	int j = 0;

// 	// int last_color;

// 	col_id = WIDTH - (col_id);
// 	cast_cel(top_p, cub, col_id);
// 	cast_floor(bottom_p, cub, col_id);
// 	while (top_p < bottom_p)
// 	{
// 		i = 0;
// 		offset_y = top_p + (cub->ray.w_height / 2) - (HEIGTH / 2);
// 		offset_y = offset_y * 
// 		(float)cub->text[cub->ray.w_id].h / cub->ray.w_height;
// 		while (i < 1)
// 		{
// 			color = 0xffffffff;
// 			color = get_color(cub, cub->ray.w_id, offset_y, i + 2);
// 			color <<= 8;
// 			color += get_color(cub, cub->ray.w_id, offset_y, i + 1);
// 			color <<= 8;
// 			color += get_color(cub, cub->ray.w_id, offset_y, i);
			
// 			// color <<= 8;
// 			j = 0;

// 			while (j++ < ratio / 4 && top_p + j < bottom_p)
// 				my_pixel_put(&cub->mlx.img, col_id, top_p + j, color);
// 			i++;
// 			// cub->mlx.img.addr[(top_p * WIDTH * 4) + col_id * 4 + i] = color;
// 		}
// 		if (ratio / 4)
// 			top_p += ratio / 4;
// 		else
// 			top_p++;
// 	}
// 	return (0);
// }

int	cast_col(int top_p, int bottom_p, t_cub *cub, int col_id)
{
	unsigned int	color;
	int				offset_y;

	col_id = WIDTH - (col_id);
	cast_cel(top_p, cub, col_id);
	cast_floor(bottom_p, cub, col_id);
	while (top_p++ < bottom_p)
	{
		offset_y = top_p + (cub->ray.w_height / 2) - (HEIGTH / 2);
		offset_y = offset_y * \
		(float)cub->text[cub->ray.w_id].h / cub->ray.w_height;
		color = get_color(cub, cub->ray.w_id, offset_y, 0);
		my_pixel_put(&cub->mlx.img, col_id, top_p, color);
	}
	return (0);
}

unsigned int	get_color(t_cub *cub, int id, int offset_y, int rgb)
{
	unsigned int	color;
	int				offset_x;
	unsigned int	*tab;

	offset_x = get_xoffset(cub);
	tab = (unsigned int *)cub->text[id].addr;
	color = tab[(cub->text[id].w * offset_y \
	+ offset_x + rgb)];
	return (color);
}

int	cast_cel(int top_p, t_cub *cub, int col_id)
{
	int	x;
	int	y;

	x = col_id;
	y = 0;
	while (y <= top_p)
	{
		my_pixel_put(&cub->mlx.img, x, y, cub->f_color);
		y++;
	}
	return (0);
}

int	cast_floor( int bottom_p, t_cub *cub, int col_id)
{
	int	x;
	int	y;

	x = col_id;
	y = bottom_p;
	while (y <= HEIGTH)
	{
		my_pixel_put(&cub->mlx.img, x, y, cub->c_color);
		y++;
	}
	return (0);
}
