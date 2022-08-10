/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:31:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:00:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_max(int a, int b);

void	minimap(t_cub *cub)
{
	int	x;
	int	y;
	int	size;

	size = 200 / ft_max(cub->height, cub->width);
	draw_box(cub, (t_co){.x = 4, .y = 4, .color = cub->c_color},
		(t_co){.x = size * cub->width + 6, .y = size * cub->height + 6,});
	x = 0;
	while (x <= cub->width)
	{
		y = 0;
		while (y <= cub->height)
		{
			if (cub->char_map[y][x] == '1')
			{
				draw_box(cub, (t_co){.x = 5 + (size * (x)),
					.y = 5 + (size * (y - 1)), .color = cub->f_color},
					(t_co){.x = 5 + (size * x) + size,
					.y = 5 + (size * y)});
			}
			y++;
		}
		x++;
	}
	draw_box(cub, (t_co){.x = cub->player->x / TILE_SIZE * size + 5,
		.y = cub->player->y / TILE_SIZE * size + 5, .color = 0x00ff0000},
		(t_co){.x = cub->player->x / TILE_SIZE * size + 8, .y = cub->player->y / TILE_SIZE * size + 8});
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}