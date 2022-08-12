/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:31:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/12 17:18:29 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_max(int a, int b);
static void	put_map_walls(t_cub *cub, int x, int y, int size);

void	minimap(t_cub *cub)
{
	int	x;
	int	y;
	int	size;

	size = 200 / ft_max(cub->height, cub->width);
	draw_box(cub, (t_co){.x = 4, .y = 4, .color = cub->c_color},
		(t_co){.x = size * cub->width + 6, .y = size * cub->height + 6,});
	x = -1;
	while (x++ <= cub->width)
	{
		y = -1;
		while (y++ <= cub->height)
			put_map_walls(cub, x, y, size);
	}
	draw_box(cub, (t_co){.x = cub->player->x / TILE_SIZE * size + 5,
		.y = cub->player->y / TILE_SIZE * size + 5, .color = 0x00ff0000},
		(t_co){.x = cub->player->x / TILE_SIZE * size + 8,
		.y = cub->player->y / TILE_SIZE * size + 8});
}

static void	put_map_walls(t_cub *cub, int x, int y, int size)
{
	if (cub->char_map[y][x] == '1')
	{
		draw_box(cub, (t_co){.x = 5 + (size * (x)),
			.y = 5 + (size * (y - 1)), .color = cub->f_color},
			(t_co){.x = 5 + (size * x) + size,
			.y = 5 + (size * y)});
	}
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
