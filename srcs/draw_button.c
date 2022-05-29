/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:32:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/29 21:58:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_button(t_menu *menu, int key)
{
	static int	button = 0;

	if ((key == UP_KEY || key == RIGHT_KEY) && button != 1)
		button--;
	else if ((key == DOWN_KEY || key == LEFT_KEY) && button != MENU_BUTTONS)
		button++;
	else
		return ;
	remove_border(&menu->img, menu->last_button);
	draw_borders(&menu->img, (t_co){.x = 400, .y = 250 + ((button - 1) * 250)}, MENU_COLOR);
	menu->last_button = (t_co){.x = 400, .y = 250 + ((button - 1) * 250)};
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

void	draw_borders(t_img *img, t_co co, int color)
{
	straight_line(img, co, 400, DIR_X, color - LIL_SHDW_DIFF);
	straight_line(img, co, 200, DIR_Y, color - LIL_SHDW_DIFF);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 200}, 400, DIR_X, color - LIL_SHDW_DIFF);
	straight_line(img, (t_co){.x = co.x + 400, .y = co.y}, 200, DIR_Y, color - LIL_SHDW_DIFF);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20}, 360, DIR_X, color);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 180}, 360, DIR_X, color);
	straight_line(img, (t_co){.x = co.x + 380, .y = co.y + 20}, 160, DIR_Y, color);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20}, 160, DIR_Y, color);
	diagonale(img, co, 20, DOWNSIDE, color - LIL_SHDW_DIFF);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 180}, 20, DOWNSIDE, color - LIL_SHDW_DIFF);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 200}, 20, UPSIDE, color - LIL_SHDW_DIFF);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 20}, 20, UPSIDE, color - LIL_SHDW_DIFF);
}

void	remove_border(t_img *img, t_co co)
{
	int color;

	color = 0;
	straight_line(img, co, 400, DIR_X, color);
	straight_line(img, co, 200, DIR_Y, color);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 200}, 400, DIR_X, color);
	straight_line(img, (t_co){.x = co.x + 400, .y = co.y}, 200, DIR_Y, color);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20}, 360, DIR_X, color);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 180}, 360, DIR_X, color);
	straight_line(img, (t_co){.x = co.x + 380, .y = co.y + 20}, 160, DIR_Y, color);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20}, 160, DIR_Y, color);
	diagonale(img, co, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 180}, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 200}, 20, UPSIDE, color);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 20}, 20, UPSIDE, color);
}