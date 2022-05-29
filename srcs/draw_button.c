/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:32:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/29 18:56:02 by nguiard          ###   ########.fr       */
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
	draw_borders(&menu->img, menu->last_button, BLACK);
	draw_borders(&menu->img, (t_co){.x = 400, .y = 200 + ((button - 1) * 250)}, GREEN);
	menu->last_button = (t_co){.x = 400, .y = 200 + ((button - 1) * 250)};
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

void	draw_borders(t_img *img, t_co co, int color)
{
	straight_line(img, co, 400, DIR_X, color);
	straight_line(img, co, 200, DIR_Y, color);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 200}, 400, DIR_X, color);
	straight_line(img, (t_co){.x = co.x + 400, .y = co.y}, 200, DIR_Y, color);
}