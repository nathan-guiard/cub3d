/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:27:58 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 23:24:42 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_north(t_menu *menu, int x, int y);
static void	draw_east(t_menu *menu, int x, int y);
static void	draw_west(t_menu *menu, int x, int y);
static void	draw_south(t_menu *menu, int x, int y);

void	draw_player(t_menu *menu, char key, int x, int y)
{
	if (key == 'N')
		draw_north(menu, x, y);
	else if (key == 'E')
		draw_east(menu, x, y);
	else if (key == 'S')
		draw_south(menu, x, y);
	else
		draw_west(menu, x, y);
}

static void	draw_north(t_menu *menu, int x, int y)
{
	t_co	co;

	co = (t_co){.x = 50 + (x * 50), .y = 200 + (y * 50), .color = PLAYER_COLOR};
	mlx_putstr(&menu->img, "N", (t_co){.x = co.x + 5, .y = co.y + 35,
		.color = PLAYER_COLOR}, 1);
	straight_line(&menu->img, (t_co){.x = co.x + 20, .y = co.y + 25,
		.color = co.color}, 20, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 30, .y = co.y + 25,
		.color = co.color}, 20, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 10, .y = co.y + 25,
		.color = co.color}, 10, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 30, .y = co.y + 25,
		.color = co.color}, 10, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 20, .y = co.y + 45,
		.color = co.color}, 10, DIR_X);
	menu_bg_line(menu->img, (t_co){.x = co.x + 10, .y = co.y + 25,
		.color = co.color}, (t_co){.x = co.x + 26, .y = co.y + 5});
	menu_bg_line(menu->img, (t_co){.x = co.x + 40, .y = co.y + 25,
		.color = co.color}, (t_co){.x = co.x + 24, .y = co.y + 5});
}

static void	draw_east(t_menu *menu, int x, int y)
{
	t_co	co;

	co = (t_co){.x = 50 + (x * 50), .y = 200 + (y * 50), .color = PLAYER_COLOR};
	mlx_putstr(&menu->img, "E", (t_co){.x = co.x + 5, .y = co.y + 35,
		.color = PLAYER_COLOR}, 1);
	straight_line(&menu->img, (t_co){.x = co.x + 5, .y = co.y + 20,
		.color = co.color}, 20, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 5, .y = co.y + 30,
		.color = co.color}, 20, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 5, .y = co.y + 20,
		.color = co.color}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 25, .y = co.y + 10,
		.color = co.color}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 25, .y = co.y + 30,
		.color = co.color}, 10, DIR_Y);
	menu_bg_line(menu->img, (t_co){.x = co.x + 25, .y = co.y + 10,
		.color = co.color}, (t_co){.x = co.x + 45, .y = co.y + 25});
	menu_bg_line(menu->img, (t_co){.x = co.x + 45, .y = co.y + 25,
		.color = co.color}, (t_co){.x = co.x + 25, .y = co.y + 40});
}

static void	draw_south(t_menu *menu, int x, int y)
{
	t_co	co;

	co = (t_co){.x = 50 + (x * 50), .y = 200 + (y * 50), .color = PLAYER_COLOR};
	mlx_putstr(&menu->img, "S", (t_co){.x = co.x + 35, .y = co.y + 5,
		.color = PLAYER_COLOR}, 1);
	straight_line(&menu->img, (t_co){.x = co.x + 20, .y = co.y + 5,
		.color = co.color}, 20, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 30, .y = co.y + 5,
		.color = co.color}, 20, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 20, .y = co.y + 5,
		.color = co.color}, 10, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 30, .y = co.y + 25,
		.color = co.color}, 10, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 10, .y = co.y + 25,
		.color = co.color}, 10, DIR_X);
	menu_bg_line(menu->img, (t_co){.x = co.x + 10, .y = co.y + 25,
		.color = co.color}, (t_co){.x = co.x + 26, .y = co.y + 45});
	menu_bg_line(menu->img, (t_co){.x = co.x + 40, .y = co.y + 25,
		.color = co.color}, (t_co){.x = co.x + 24, .y = co.y + 45});
}

static void	draw_west(t_menu *menu, int x, int y)
{
	t_co	co;

	co = (t_co){.x = 50 + (x * 50), .y = 200 + (y * 50), .color = PLAYER_COLOR};
	mlx_putstr(&menu->img, "W", (t_co){.x = co.x + 35, .y = co.y + 5,
		.color = PLAYER_COLOR}, 1);
	straight_line(&menu->img, (t_co){.x = co.x + 25, .y = co.y + 20,
		.color = co.color}, 20, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 45, .y = co.y + 20,
		.color = co.color}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 25, .y = co.y + 30,
		.color = co.color}, 20, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 25, .y = co.y + 10,
		.color = co.color}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 25, .y = co.y + 30,
		.color = co.color}, 10, DIR_Y);
	menu_bg_line(menu->img, (t_co){.x = co.x + 5, .y = co.y + 25,
		.color = co.color}, (t_co){.x = co.x + 25, .y = co.y + 10});
	menu_bg_line(menu->img, (t_co){.x = co.x + 25, .y = co.y + 40,
		.color = co.color}, (t_co){.x = co.x + 5, .y = co.y + 25});
}
