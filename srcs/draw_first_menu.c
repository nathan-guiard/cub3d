/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:00:11 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/30 15:55:04 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cub3d(t_img *img, int x, int y, int color);
void	draw_3(t_img *img, int x, int y, int color);
void	draw_relief(t_img *img, int x, int y, int color);
void	draw_box(t_img *img, t_co start , t_co end);

void	draw_first_menu(t_menu *menu)
{
	ft_j(&menu->img, (t_co){.x = 900, .y = 500, 0x00ffffff}, 10);
	draw_box(&menu->img, (t_co){.x = 320, .y = 35, .color = 0x00001700}, (t_co){.x = 880, .y = 185});
	draw_button(menu, DOWN_KEY);
	draw_cub3d(&menu->img, 360, 70, MENU_COLOR);
	draw_relief(&menu->img, 360, 70, MENU_COLOR - SHADOW_DIFF);
}

void	draw_cub3d(t_img *img, int x, int y, int color)
{
	straight_line(img, (t_co){.x = x, .y = y, .color = color}, 290, DIR_X);
	straight_line(img, (t_co){.x = x, .y = y + 100, .color = color}, 290, DIR_X);
	straight_line(img, (t_co){.x = x + 50, .y = y + 50, .color = color}, 50, DIR_X);
	straight_line(img, (t_co){.x = x, .y = y, .color = color}, 100, DIR_Y);
	straight_line(img, (t_co){.x = x + 100, .y = y, .color = color}, 100, DIR_Y);
	straight_line(img, (t_co){.x = x + 200, .y = y, .color = color}, 100, DIR_Y);
	straight_line(img, (t_co){.x = x + 150, .y = y, .color = color}, 50, DIR_Y);
	diagonale(img, (t_co){.x = x + 290, .y = y, .color = color}, 10, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 290, .y = y + 100, .color = color}, 10, UPSIDE);
	straight_line(img, (t_co){.x = x + 300, .y = y + 10, .color = color}, 30, DIR_Y);
	straight_line(img, (t_co){.x = x + 250, .y = y + 50, .color = color}, 40, DIR_X);
	diagonale(img, (t_co){.x = x + 290, .y = y + 50, .color = color}, 10, UPSIDE);
	straight_line(img, (t_co){.x = x + 300, .y = y + 60, .color = color}, 30, DIR_Y);
	diagonale(img, (t_co){.x = x + 290, .y = y + 50, .color = color}, 10, DOWNSIDE);
	draw_3(img, x + 300, y, color);
	straight_line(img, (t_co){.x = x + 401, .y = y, .color = color}, 100, DIR_Y);
	straight_line(img, (t_co){.x = x + 501, .y = y + 10, .color = color}, 80, DIR_Y);
	straight_line(img, (t_co){.x = x + 400, .y = y, .color = color}, 90, DIR_X);
	straight_line(img, (t_co){.x = x + 450, .y = y + 40, .color = color}, 20, DIR_Y);
	straight_line(img, (t_co){.x = x + 400, .y = y + 100, .color = color}, 90, DIR_X);
	diagonale(img, (t_co){.x = x + 490, .y = y + 100, .color = color}, 10, UPSIDE);
	diagonale(img, (t_co){.x = x + 490, .y = y, .color = color}, 10, DOWNSIDE);
}

void	draw_3(t_img *img, int x, int y, int color)
{
	color += THREE_DIFF;
	straight_line(img, (t_co){.x = x + 10, .y = y, .color = color}, 90, DIR_X);
	diagonale(img, (t_co){.x = x, .y = y + 10, .color = color}, 10, UPSIDE);
	diagonale(img, (t_co){.x = x, .y = y + 90, .color = color}, 10, DOWNSIDE);
	straight_line(img, (t_co){.x = x, .y = y + 40, .color = color}, 20, DIR_X);
	straight_line(img, (t_co){.x = x, .y = y + 60, .color = color}, 20, DIR_X);
	straight_line(img, (t_co){.x = x + 10, .y = y + 100, .color = color}, 90, DIR_X);
	diagonale(img, (t_co){.x = x + 20, .y = y + 60, .color = color}, 10, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 20, .y = y + 40, .color = color}, 10, UPSIDE);
	straight_line(img, (t_co){.x = x + 30, .y = y + 70, .color = color}, 40, DIR_X);
	straight_line(img, (t_co){.x = x + 30, .y = y + 30, .color = color}, 40, DIR_X);
	straight_line(img, (t_co){.x = x + 70, .y = y + 30, .color = color}, 10, DIR_Y);
	straight_line(img, (t_co){.x = x + 70, .y = y + 60, .color = color}, 10, DIR_Y);
	straight_line(img, (t_co){.x = x + 40, .y = y + 40, .color = color}, 30, DIR_X);
	straight_line(img, (t_co){.x = x + 40, .y = y + 60, .color = color}, 30, DIR_X);
	straight_line(img, (t_co){.x = x + 40, .y = y + 40, .color = color}, 20, DIR_Y);
	straight_line(img, (t_co){.x = x + 100, .y = y, .color = color}, 100, DIR_Y);
}

void	draw_relief(t_img *img, int x, int y, int color)
{
	x -= 20;
	y -= 20;
	straight_line(img, (t_co){.x = x, .y = y, .color = color}, 290, DIR_X);
	straight_line(img, (t_co){.x = x, .y = y, .color = color}, 100, DIR_Y);
	diagonale(img, (t_co){.x = x, .y = y, .color = color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = x, .y = y + 100, .color = color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 290, .y = y, .color = color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 300, .y = y + 10, .color = color + THREE_DIFF}, 10, UPSIDE);
	diagonale(img, (t_co){.x = x + 310, .y = y, .color = color  + THREE_DIFF}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 400, .y = y, .color = color  + THREE_DIFF}, 20, DOWNSIDE);
	straight_line(img, (t_co){.x = x + 310, .y = y, .color = color  + THREE_DIFF}, 90, DIR_X);
	straight_line(img, (t_co){.x = x + 400, .y = y, .color = color}, 90, DIR_X);
	diagonale(img, (t_co){.x = x + 490, .y = y, .color = color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 100, .y = y, .color = color}, 20, DOWNSIDE);
	diagonale(img, (t_co){.x = x + 200, .y = y, .color = color}, 20, DOWNSIDE);	
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