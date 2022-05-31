/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:00:11 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/31 15:41:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cub3d(t_img *img, int x, int y, int color);
void	draw_3(t_img *img, int x, int y, int color);
void	draw_relief(t_img *img, int x, int y, int color);
void	draw_box(t_img *img, t_co start , t_co end);

void	draw_first_menu(t_menu *menu)
{
	draw_box(&menu->img, (t_co){.x = 320, .y = 35, .color = 0x00001700}, (t_co){.x = 880, .y = 185});
	mlx_putstr(&menu->img, "cub", (t_co){.x = 110, .y = 70, MENU_COLOR}, 10);
	mlx_putstr(&menu->img, "tron", (t_co){.x = 410, .y = 70, MENU_COLOR + THREE_DIFF}, 10);
	mlx_putstr(&menu->img, "d", (t_co){.x = 810, .y = 70, MENU_COLOR}, 10);
	draw_button(menu, DOWN_KEY);
	mlx_putstr(&menu->img, "abcdefghijklmnopqrstuvwxyz0123456789./", (t_co){.x = 50, .y = 600, MENU_COLOR}, 2);
}

void	draw_box(t_img *img, t_co start , t_co end)
{
	int	save;

	save = start.x;
	while(start.y < end.y)
	{
		while(start.x < end.x)
		{
			my_pixel_put(img, start.x, start.y, start.color);
			start.x++;
		}
		start.y++;
		start.x = save;
	}
}