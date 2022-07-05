/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ask_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:36:35 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/05 15:13:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_ask_name(t_menu *menu)
{
	draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
		(t_co){.x = WIDTH, .y = HEIGTH});
	draw_box(menu, (t_co){.x = 290, .y = 50,
		.color = MENU_COLOR + THREE_DIFF - SHADOW_DIFF},
		(t_co){.x = 880, .y = 250});
	mlx_putstr(&menu->img, "choose a",
		(t_co){.x = 340, .y = 75, .color = BLACK}, 6);
	mlx_putstr(&menu->img, "map name",
		(t_co){.x = 340, .y = 165, .color = BLACK}, 6);
	draw_box(menu, (t_co){.x = 175, .y = 405,
		.color = MENU_COLOR + THREE_DIFF},
		(t_co){.x = 1030, .y = 496});
	draw_box(menu, (t_co){.x = 180, .y = 410, .color = BLACK},
		(t_co){.x = 1025, .y = 491});
}