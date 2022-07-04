/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:35:06 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/23 22:22:22 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_arrow(t_menu *menu, int color);
static void	draw_arrow2(t_menu *menu, int color);
void	draw_first_maps_name(t_menu *menu);

void	draw_play(t_menu *menu)
{
	draw_box(menu, (t_co){.x = 0, .y = 0, .color = 0},
		(t_co){.x = WIDTH, .y = HEIGTH});
	mlx_putstr(&menu->img, "Choose a map", (t_co){.x = 240, .y = 50, .color = GREEN}, 6);
	draw_box(menu, (t_co){.x = 300, .y = 200, .color = 0x00004000},
		(t_co){.x = 900, .y = 300});
	draw_box(menu, (t_co){.x = 300, .y = 300, .color = 0x00006000},
		(t_co){.x = 900, .y = 400});
	draw_box(menu, (t_co){.x = 300, .y = 400, .color = 0x00008000},
		(t_co){.x = 900, .y = 500});
	draw_box(menu, (t_co){.x = 300, .y = 500, .color = 0x00006000},
		(t_co){.x = 900, .y = 600});
	draw_box(menu, (t_co){.x = 300, .y = 600, .color = 0x00004000},
		(t_co){.x = 900, .y = 700});
	draw_arrow(menu, GREEN);
	draw_arrow2(menu, 0x00008000);
	draw_first_maps_name(menu);
}

static void	draw_arrow(t_menu *menu, int color)
{
	straight_line(&menu->img, (t_co){.x = 75, .y = 410,
		.color = color}, 80, DIR_Y);
	straight_line(&menu->img, (t_co){.x = 75, .y = 410,
		.color = color}, 100, DIR_X);
	straight_line(&menu->img, (t_co){.x = 75, .y = 490,
		.color = color}, 100, DIR_X);
	straight_line(&menu->img, (t_co){.x = 175, .y = 370,
		.color = color}, 40, DIR_Y);
	straight_line(&menu->img, (t_co){.x = 175, .y = 490,
		.color = color}, 40, DIR_Y);
	diagonale(&menu->img, (t_co){.x = 175, .y = 370,
		.color = color}, 81, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 175, .y = 530,
		.color = color}, 81, UPSIDE);
}

static void	draw_arrow2(t_menu *menu, int color)
{
	diagonale(&menu->img, (t_co){.x = 75, .y = 489,
		.color = color}, 40, UPSIDE);
	diagonale(&menu->img, (t_co){.x = 105, .y = 489,
		.color = color}, 40, UPSIDE);
	diagonale(&menu->img, (t_co){.x = 135, .y = 489,
		.color = color}, 40, UPSIDE);
	diagonale(&menu->img, (t_co){.x = 165, .y = 489,
		.color = color}, 40, UPSIDE);
	diagonale(&menu->img, (t_co){.x = 176, .y = 510,
		.color = color}, 61, UPSIDE);
	diagonale(&menu->img, (t_co){.x = 176, .y = 390,
		.color = color}, 60, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 75, .y = 411,
		.color = color}, 40, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 105, .y = 411,
		.color = color}, 40, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 135, .y = 411,
		.color = color}, 40, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 165, .y = 411,
		.color = color}, 40, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 76, .y = 440,
		.color = color}, 11, DOWNSIDE);
	diagonale(&menu->img, (t_co){.x = 76, .y = 460,
		.color = color}, 10, UPSIDE);
}

void	draw_first_maps_name(t_menu *menu)
{
	char	**tab;
	t_list	*lst;

	lst = get_map_list();
	tab = define_map_tab(lst, 0);
	put_play_maps(menu, tab);
	custom_free_tabtab(tab);
	destroy_map_list(lst);
}