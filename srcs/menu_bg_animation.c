/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bg_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:18:36 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/01 21:43:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	menu_bg_animation(t_menu *menu)
{
	static int	i = 0;

	menu->key_pressed = 0;
	while (menu->key_pressed != 1)
	{
		i++;
		//ft_printf("%d\t\t\t%d\n", i, frame);
		if (i / ANIM_LOOP == (i - 1) / ANIM_LOOP)
		{
			straight_line(&menu->img, (t_co){.x = i / ANIM_LOOP, .y = 0, .color = 0x00000000}, 500, DIR_Y);
			straight_line(&menu->img, (t_co){.x = (i / ANIM_LOOP) + 1, .y = 0, .color = 0x00ff0000}, 500, DIR_Y);
			//draw_menu(menu);
			mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		}
		if (i == 100 * ANIM_LOOP)
			i = 0;
	}
}