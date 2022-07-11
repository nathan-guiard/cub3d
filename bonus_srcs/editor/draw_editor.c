/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:56:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/11 10:24:40 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	header(t_menu *menu, char *map);
static void	grid(t_menu *menu);
// static void	colors(t_menu *menu);

void	draw_editor(t_menu *menu, char *map)
{
	draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
		(t_co){.x = WIDTH, .y = HEIGTH});
	menu->last_button = (t_co){.x = 50, .y = 200, .color = GREEN};
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
	mlx_putstr(&menu->img, "map editor", (t_co){.x = 50, .y = 50, .color = GREEN}, 2);
	mlx_putstr(&menu->img, str, (t_co){.x = 50, .y = 140, .color = GREEN}, 3);
	mlx_putstr(&menu->img, "Bindings", (t_co){.x = 850, .y = 50, .color = GREEN}, 2);
	mlx_putstr(&menu->img, "move    arrows", (t_co){.x = 850, .y = 90, .color = GREEN}, 2);
	mlx_putstr(&menu->img, "player  wasd", (t_co){.x = 850, .y = 120, .color = GREEN}, 2);
	mlx_putstr(&menu->img, "wall    q", (t_co){.x = 850, .y = 150, .color = GREEN}, 2);
	free(str);
}

static void	grid(t_menu *menu)
{
	int	i;

	i = 100;
	draw_box(menu, (t_co){.x = 50, .y = 200, .color = THREE_BLUE - SHADOW_DIFF},
		(t_co){.x = WIDTH - 50, .y = HEIGTH - 50});
	draw_box(menu, (t_co){.x = 51, .y = 201, .color = BLACK},
		(t_co){.x = WIDTH - 51, .y = HEIGTH - 51});
	ft_printf("color: %x\n", THREE_BLUE);
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

// static void	colors(t_menu *menu)
// {
// 	mlx_putstr(&menu->img, "ceiling", (t_co){.x = 750, .y = 50, .color = GREEN}, 2);
// 	draw_box(menu, (t_co){.x = 1120, .y = 45, .color = 0x00404040},
// 		(t_co){.x = 1150, .y = 75});
// 	draw_box(menu, (t_co){.x = 900, .y = 45, .color = GREEN},
// 		(t_co){.x = 1110, .y = 75});
// 	draw_box(menu, (t_co){.x = 901, .y = 46, .color = BLACK},
// 		(t_co){.x = 1109, .y = 74});
// 	mlx_putstr(&menu->img, "floor", (t_co){.x = 750, .y = 120, .color = GREEN}, 2);
// 	draw_box(menu, (t_co){.x = 1120, .y = 115, .color = 0x00404040},
// 		(t_co){.x = 1150, .y = 145});
// 	draw_box(menu, (t_co){.x = 900, .y = 115, .color = GREEN},
// 		(t_co){.x = 1110, .y = 145});
// 	draw_box(menu, (t_co){.x = 901, .y = 116, .color = BLACK},
// 		(t_co){.x = 1109, .y = 144});
// 	mlx_putstr(&menu->img, "0", (t_co){.x = 905, .y = 50, .color = 0x00ff0000}, 2);
// 	mlx_putstr(&menu->img, "0", (t_co){.x = 975, .y = 50, .color = GREEN}, 2);
// 	mlx_putstr(&menu->img, "0", (t_co){.x = 1045, .y = 50, .color = 0x000000ff}, 2);
// 	mlx_putstr(&menu->img, "0", (t_co){.x = 905, .y = 120, .color = 0x00ff0000}, 2);
// 	mlx_putstr(&menu->img, "0", (t_co){.x = 975, .y = 120, .color = GREEN}, 2);
// 	mlx_putstr(&menu->img, "0", (t_co){.x = 1045, .y = 120, .color = 0x000000ff}, 2);
// }