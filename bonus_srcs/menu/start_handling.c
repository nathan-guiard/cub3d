/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:30:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 20:23:01 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	start_handling(int key, t_menu *menu)
{
	unsigned long long	time_time;

	time_time = get_elapsedtime(menu->base_time);
	if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY || key == RIGHT_KEY)
		draw_menu_button(menu, key);
	if (key == ENTER && menu->button == 1 &&
		time_time >= 1)
	{
		draw_play(menu);
		menu->status = play;
	}
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}