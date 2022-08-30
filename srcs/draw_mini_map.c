/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:01:24 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/30 11:06:21 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_grid(t_cub *cub, t_cords *cords, int fill)
{
	cords->tile_size = 32;
	cords->scale = 1;
	cords->temp_y = cords->y;
	cords->temp_x = cords->x;
	cords->end_x = cords->x + (cords->tile_size * cords->scale);
	cords->end_y = cords->y + (cords->tile_size * cords->scale);
	if (fill == 1 || fill == 2)
	{
		full_square(cords, cub, fill);
		return (0);
	}
	while (cords->x < cords->end_x && cords->x < WIDTH && cords->x > 0)
		my_pixel_put(&cub->mlx.img, cords->x++, cords->y, cub->f_color);
	while (cords->y < cords->end_y && cords->y < HEIGTH && cords->y > 0)
		my_pixel_put(&cub->mlx.img, cords->x, cords->y++, cub->c_color);
	while (cords->temp_y < cords->end_y && cords->y < HEIGTH)
		my_pixel_put(&cub->mlx.img, cords->temp_x,
			cords->temp_y++, cub->f_color);
	while (cords->temp_x < cords->end_x && cords->x < WIDTH)
		my_pixel_put(&cub->mlx.img, cords->temp_x++, cords->y, cub->f_color);
	cords->y = cords->y - cords->tile_size * cords->scale;
	return (0);
}

int	full_square(t_cords *cords, t_cub *cub, int fill)
{
	unsigned int	color;

	if (fill == 1)
		color = cub->c_color;
	else if (fill == 2)
		color = cub->f_color;
	while (cords->y < cords->end_y && cords->y < HEIGTH)
	{
		while (cords->x < cords->end_x && cords->x < WIDTH)
			my_pixel_put(&cub->mlx.img, cords->x++, cords->y, color);
		cords->x = cords->temp_x;
		my_pixel_put(&cub->mlx.img, cords->temp_x, cords->y++, color);
	}
	cords->x = cords->end_x;
	return (0);
}
