/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:41:47 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/11 17:44:41 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	move_cursor(t_menu *menu, int key)
{
	draw_box(menu, (t_co){.x = menu->button_co.x, menu->button_co.y,
		.color = THREE_BLUE - SHADOW_DIFF},
		(t_co){.x = menu->button_co.x + 51, menu->button_co.y + 51});
	draw_box(menu, (t_co){.x = menu->button_co.x + 1,
		menu->button_co.y + 1, .color = BLACK},
		(t_co){.x = menu->button_co.x + 50, menu->button_co.y + 50});
	if (key == UP_KEY && menu->button_co.y > 200)
		menu->button_co.y -= 50;
	if (key == DOWN_KEY && menu->button_co.y < HEIGTH - 101)
		menu->button_co.y += 50;
	if (key == RIGHT_KEY && menu->button_co.x < WIDTH - 101)
		menu->button_co.x += 50;
	if (key == LEFT_KEY && menu->button_co.x > 50)
		menu->button_co.x -= 50;		
}

void	build_handling(t_menu *menu, int key)
{
	if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY || key == RIGHT_KEY)
		move_cursor(menu, key);
	else if (key == 'q')
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = '1';
	else if (key == DEL)
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = '0';
	draw_charmap(menu);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}