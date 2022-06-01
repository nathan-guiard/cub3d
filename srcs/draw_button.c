/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:32:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/01 17:48:51 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_button(t_menu *menu, int key)
{
	if ((key == UP_KEY || key == RIGHT_KEY) && menu->button != 1)
		menu->button--;
	else if ((key == DOWN_KEY || key == LEFT_KEY) && menu->button != MENU_BUTTONS)
		menu->button++;
	else if (key == 0)
		;
	else
		return ;
	remove_border(&menu->img, menu->last_button);
	if (menu->button == 1 && key != 0)
	{
		draw_borders(&menu->img, (t_co){.x = 400, 
			.y = 250 + ((menu->button - 1) * 250), .color = MENU_COLOR});
		menu->last_button = (t_co){.x = 400, .y = 250 + ((menu->button - 1) * 250)};
	}
	else if (menu->button == 2 && key != 0)
	{
		draw_borders(&menu->img, (t_co){.x = 400, 
			.y = 250 + ((menu->button - 1) * 250), .color = MENU_COLOR});
		menu->last_button = (t_co){.x = 400, .y = 250 + ((menu->button - 1) * 250)};
	}
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

void	draw_borders(t_img *img, t_co co)
{
	straight_line(img, co, 400, DIR_X);
	straight_line(img, co, 200, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 200, .color = co.color}, 400, DIR_X);
	straight_line(img, (t_co){.x = co.x + 400, .y = co.y, .color = co.color}, 200, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20, .color = co.color}, 360, DIR_X);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 180, .color = co.color}, 360, DIR_X);
	straight_line(img, (t_co){.x = co.x + 380, .y = co.y + 20, .color = co.color}, 160, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20, .color = co.color}, 160, DIR_Y);
	diagonale(img, co, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 180, .color = co.color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 200, .color = co.color}, 20, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 20, .color = co.color}, 20, UPSIDE);
}

void	remove_border(t_img *img, t_co co)
{
	co.color = 0x00404040;
	straight_line(img, co, 400, DIR_X);
	straight_line(img, co, 200, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 200, .color = co.color}, 400, DIR_X);
	straight_line(img, (t_co){.x = co.x + 400, .y = co.y, .color = co.color}, 200, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20, .color = co.color}, 360, DIR_X);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 180, .color = co.color}, 360, DIR_X);
	straight_line(img, (t_co){.x = co.x + 380, .y = co.y + 20, .color = co.color}, 160, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 20, .y = co.y + 20, .color = co.color}, 160, DIR_Y);
	diagonale(img, co, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 180, .color = co.color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 200, .color = co.color}, 20, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 380, .y = co.y + 20, .color = co.color}, 20, UPSIDE);
}