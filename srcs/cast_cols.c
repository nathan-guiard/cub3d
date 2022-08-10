/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_cols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:12:20 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/10 12:02:33 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	cast_col(int top_p, int bottom_p, t_cub *cub, int col_id)
{
	unsigned int	color;
	int				offset_y;
	int				i;

	cast_cel(top_p, cub, col_id);
	cast_floor(bottom_p, cub, col_id);
	col_id = WIDTH - (col_id * cub->col_width);
	while (top_p++ < bottom_p)
	{
		i = 0;
		offset_y = top_p + (cub->ray.w_height / 2) - (HEIGTH / 2);
		offset_y = offset_y * \
		(float)cub->text[cub->ray.w_id].h / cub->ray.w_height;
		while (i < 3)
		{
			color = get_color(cub, cub->ray.w_id, offset_y, i);
			cub->mlx.img.addr[(top_p * WIDTH * 4) + col_id * 4 + i] = color;
			i++;
		}
	}
	return (0);
}

unsigned int	get_color(t_cub *cub, int id, int offset_y, int rgb)
{
	unsigned int	color;
	int				offset_x;
	int				calc;

	offset_x = get_xoffset(cub);
	calc = (cub->text[id].w * offset_y * 4 \
	+ offset_x * 4 + rgb);
	color = cub->text[id].addr[calc];
	return (color);
}

int	cast_cel(int top_p, t_cub *cub, int col_id)
{
	int	i;
	int	x;
	int	save;

	x = WIDTH - (col_id * cub->col_width);
	save = 0;
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

int	cast_floor( int bottom_p, t_cub *cub, int col_id)
{
	int	i;
	int	x;
	int	save;

	x = WIDTH - (col_id * cub->col_width);
	save = bottom_p;
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
