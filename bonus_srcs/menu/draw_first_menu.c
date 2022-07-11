/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:00:11 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/11 10:30:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_cub3d(t_img *img, int x, int y, int color);
void	draw_3(t_img *img, int x, int y, int color);

void	draw_first_menu(t_menu *menu)
{
	menu->last_button = (t_co){.x = 400, .y = 500};
	menu->button = 0;
	draw_menu(menu);
	draw_menu_button(menu, DOWN_KEY);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

void	draw_menu(t_menu *menu)
{
	carelage(menu, -1);
	put_carelage_x(menu);
	mlx_putstr(&menu->img, "cub", (t_co){.x = TITLE_X, .y = TITLE_Y,
		MENU_COLOR}, 10);
	mlx_putstr(&menu->img, "d", (t_co){.x = TITLE_X + 700, .y = TITLE_Y,
		MENU_COLOR}, 10);
	mlx_putstr(&menu->img, "tron", (t_co){.x = TITLE_X + 300, .y = TITLE_Y,
		THREE_BLUE}, 10);
	mlx_putstr(&menu->img, "play", (t_co){.x = 480, .y = 320,
		MENU_COLOR}, 6);
	mlx_putstr(&menu->img, "map", (t_co){.x = 540, .y = 550,
		MENU_COLOR}, 4);
	mlx_putstr(&menu->img, "building", (t_co){.x = 440, .y = 610,
		MENU_COLOR}, 4);
	draw_releif(&menu->img, (t_co){.x = TITLE_X, .y = TITLE_Y,
		MENU_COLOR - LIL_SHDW_DIFF}, 10);
}