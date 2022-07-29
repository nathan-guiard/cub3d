/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:01:24 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/27 17:55:53 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_mini_map(t_cub *cub)
{
	int		i;
	int		j;
	t_cords	cords;

	i = 1;
	j = 0;
	cords.x = 0;
	cords.y = 0;
	while (cub->char_map[i])
	{
		j = 0;
		cords.x = 0;
		while (cub->char_map[i][j])
		{
			if (cub->char_map[i][j] == '1')
			{
				draw_grid(cub, &cords, 1);
				cords.y = cords.y - cords.tile_size * cords.scale;
			}
			else if (ft_isset(cub->char_map[i][j], "NSWE") == 1)
			{
				draw_grid(cub, &cords, 2);
				cords.y = cords.y - cords.tile_size * cords.scale;
			}
			else if (cub->char_map[i][j] == 32 || cub->char_map[i][j] == 'v')
			{
				cords.x = cords.x + (cords.tile_size * cords.scale);
				//cords.y = cords.y + (cords.tile_size * cords.scale);
				j++;
				continue ;
			}
			else
			{
				draw_grid(cub, &cords, 0);
				cords.y = cords.y - cords.tile_size * cords.scale;
			}
			j++;
		}
		cords.y = cords.y + cords.tile_size * cords.scale;
		i++;
	}
	return (0);
}

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
		my_pixel_put(&cub->mlx.img, cords->temp_x, cords->temp_y++, cub->f_color);
	while (cords->temp_x < cords->end_x && cords->x < WIDTH)
		my_pixel_put(&cub->mlx.img, cords->temp_x++, cords->y, cub->f_color);
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

/* int	draw_tile(t_cub *cub,t_cords *cords, float cords->x, float cords->y)
{

}
 */