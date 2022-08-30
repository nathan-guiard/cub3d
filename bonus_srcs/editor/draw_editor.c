/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:56:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/30 11:06:12 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	header(t_menu *menu, char *map);
static void	grid(t_menu *menu);

void	draw_editor(t_menu *menu, char *map)
{
	draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
		(t_co){.x = WIDTH, .y = HEIGTH});
	menu->button_co = (t_co){.x = 50, .y = 200, .color = GREEN};
	header(menu, map);
	grid(menu);
	init_charmap(menu);
	draw_charmap(menu);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

static void	header(t_menu *menu, char *map)
{
	char	*str;

	str = ft_substr(map, 5, INT_MAX);
	mlx_putstr(&menu->img, "map editor", (t_co){.x = 50, .y = 50,
		.color = GREEN}, 2);
	mlx_putstr(&menu->img, str, (t_co){.x = 50, .y = 140,
		.color = GREEN}, 3);
	mlx_putstr(&menu->img, "Bindings", (t_co){.x = 850, .y = 50,
		.color = GREEN}, 2);
	mlx_putstr(&menu->img, "move    arrows", (t_co){.x = 850, .y = 90,
		.color = GREEN}, 2);
	mlx_putstr(&menu->img, "player  wasd", (t_co){.x = 850, .y = 120,
		.color = GREEN}, 2);
	mlx_putstr(&menu->img, "wall    q", (t_co){.x = 850, .y = 150,
		.color = GREEN}, 2);
	free(str);
}

static void	grid(t_menu *menu)
{
	int	i;

	i = 100;
	draw_box(menu, (t_co){.x = 50, .y = 200,
		.color = THREE_BLUE - SHADOW_DIFF},
		(t_co){.x = WIDTH - 50, .y = HEIGTH - 50});
	draw_box(menu, (t_co){.x = 51, .y = 201,
		.color = BLACK},
		(t_co){.x = WIDTH - 51, .y = HEIGTH - 51});
	while (i <= WIDTH - 100)
	{
		straight_line(&menu->img, (t_co){.x = i, .y = 200,
			.color = THREE_BLUE - SHADOW_DIFF}, 649, DIR_Y);
		i += 50;
	}
	i = 200;
	while (i <= HEIGTH - 100)
	{
		straight_line(&menu->img, (t_co){.x = 50, .y = i,
			.color = THREE_BLUE - SHADOW_DIFF}, 1099, DIR_X);
		i += 50;
	}
}
