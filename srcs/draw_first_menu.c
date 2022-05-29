/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:00:11 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/29 21:34:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cub3d(t_img *img, int x, int y, int color);
void	draw_3(t_img *img, int x, int y, int color);
void	draw_relief(t_img *img, int x, int y, int color);

void	draw_first_menu(t_menu *menu)
{
	draw_button(menu, DOWN_KEY);
	draw_cub3d(&menu->img, 350, 50, MENU_COLOR);
	draw_relief(&menu->img, 350, 50, MENU_COLOR - SHADOW_DIFF);
}

void	draw_cub3d(t_img *img, int x, int y, int color)
{
	straight_line(img, (t_co){.x = x, .y = y}, 290, DIR_X, color);
	straight_line(img, (t_co){.x = x, .y = y + 100}, 290, DIR_X, color);
	straight_line(img, (t_co){.x = x + 50, .y = y + 50}, 50, DIR_X, color);
	straight_line(img, (t_co){.x = x, .y = y}, 100, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 100, .y = y}, 100, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 200, .y = y}, 100, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 150, .y = y}, 50, DIR_Y, color);
	diagonale(img, (t_co){.x = x + 290, .y = y}, 10, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x + 290, .y = y + 100}, 10, UPSIDE, color);
	straight_line(img, (t_co){.x = x + 300, .y = y + 10}, 30, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 250, .y = y + 50}, 40, DIR_X, color);
	diagonale(img, (t_co){.x = x + 290, .y = y + 50}, 10, UPSIDE, color);
	straight_line(img, (t_co){.x = x + 300, .y = y + 60}, 30, DIR_Y, color);
	diagonale(img, (t_co){.x = x + 290, .y = y + 50}, 10, DOWNSIDE, color);
	draw_3(img, x + 300, y, color);
	straight_line(img, (t_co){.x = x + 401, .y = y}, 100, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 501, .y = y + 10}, 80, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 400, .y = y}, 90, DIR_X, color);
	straight_line(img, (t_co){.x = x + 450, .y = y + 40}, 20, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 400, .y = y + 100}, 90, DIR_X, color);
	diagonale(img, (t_co){.x = x + 490, .y = y + 100}, 10, UPSIDE, color);
	diagonale(img, (t_co){.x = x + 490, .y = y}, 10, DOWNSIDE, color);
}

void	draw_3(t_img *img, int x, int y, int color)
{
	color += THREE_DIFF;
	straight_line(img, (t_co){.x = x + 10, .y = y}, 90, DIR_X, color);
	diagonale(img, (t_co){.x = x, .y = y + 10}, 10, UPSIDE, color);
	diagonale(img, (t_co){.x = x, .y = y + 90}, 10, DOWNSIDE, color);
	straight_line(img, (t_co){.x = x, .y = y + 40}, 20, DIR_X, color);
	straight_line(img, (t_co){.x = x, .y = y + 60}, 20, DIR_X, color);
	straight_line(img, (t_co){.x = x + 10, .y = y + 100}, 90, DIR_X, color);
	diagonale(img, (t_co){.x = x + 20, .y = y + 60}, 10, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x + 20, .y = y + 40}, 10, UPSIDE, color);
	straight_line(img, (t_co){.x = x + 30, .y = y + 70}, 40, DIR_X, color);
	straight_line(img, (t_co){.x = x + 30, .y = y + 30}, 40, DIR_X, color);
	straight_line(img, (t_co){.x = x + 70, .y = y + 30}, 10, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 70, .y = y + 60}, 10, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 40, .y = y + 40}, 30, DIR_X, color);
	straight_line(img, (t_co){.x = x + 40, .y = y + 60}, 30, DIR_X, color);
	straight_line(img, (t_co){.x = x + 40, .y = y + 40}, 20, DIR_Y, color);
	straight_line(img, (t_co){.x = x + 100, .y = y}, 100, DIR_Y, color);
}

void	draw_relief(t_img *img, int x, int y, int color)
{
	x -= 20;
	y -= 20;
	straight_line(img, (t_co){.x = x, .y = y}, 290, DIR_X, color);
	straight_line(img, (t_co){.x = x, .y = y}, 100, DIR_Y, color);
	diagonale(img, (t_co){.x = x, .y = y}, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x, .y = y + 100}, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x + 290, .y = y}, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x + 300, .y = y + 10}, 10, UPSIDE, color + THREE_DIFF);
	diagonale(img, (t_co){.x = x + 310, .y = y}, 20, DOWNSIDE, color + THREE_DIFF);
	diagonale(img, (t_co){.x = x + 400, .y = y}, 20, DOWNSIDE, color + THREE_DIFF);
	straight_line(img, (t_co){.x = x + 310, .y = y}, 90, DIR_X, color + THREE_DIFF);
	straight_line(img, (t_co){.x = x + 400, .y = y}, 90, DIR_X, color);
	diagonale(img, (t_co){.x = x + 490, .y = y}, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x + 100, .y = y}, 20, DOWNSIDE, color);
	diagonale(img, (t_co){.x = x + 200, .y = y}, 20, DOWNSIDE, color);	
}