/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:00:11 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/31 17:35:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cub3d(t_img *img, int x, int y, int color);
void	draw_3(t_img *img, int x, int y, int color);
void	draw_box(t_img *img, t_co start , t_co end);

void	draw_first_menu(t_menu *menu)
{
	mlx_putstr(&menu->img, "cub", (t_co){.x = 210, .y = 70, MENU_COLOR}, 10);
	mlx_putstr(&menu->img, "tron", (t_co){.x = 511, .y = 70, MENU_COLOR + THREE_DIFF}, 10);
	mlx_putstr(&menu->img, "d", (t_co){.x = 912, .y = 70, MENU_COLOR}, 10);
	mlx_putstr(&menu->img, "play", (t_co){.x = 480, .y = 320, MENU_COLOR}, 6);
	mlx_putstr(&menu->img, "map", (t_co){.x = 540, .y = 550, MENU_COLOR}, 4);
	mlx_putstr(&menu->img, "building", (t_co){.x = 440, .y = 610, MENU_COLOR}, 4);
	draw_releif(&menu->img, (t_co){.x = 210, .y = 70, MENU_COLOR - LIL_SHDW_DIFF}, 10);
	draw_button(menu, DOWN_KEY);
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