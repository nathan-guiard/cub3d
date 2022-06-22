/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:36:46 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 18:43:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	play_handling(t_menu *menu, int key)
{
	if (key == ESC)
	{
		menu->button = 0;
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = 0},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		remove_border(&menu->img, (t_co){.x = 400, .y = 500});
		mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		menu->status = start;
	}
}