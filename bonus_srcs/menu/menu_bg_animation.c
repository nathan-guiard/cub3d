/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bg_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:18:36 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:32:30 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	*menu_bg_animation(void *arg)
{
	static int	i = 0;
	t_menu		*menu;

	menu = (t_menu *)arg;
	menu->key_pressed = 0;
	while (1)
	{
		usleep(500000);
		i++;
		pthread_mutex_lock(menu->mutex_img);
		carelage(menu, i);
		put_carelage_x(menu);
		pthread_mutex_unlock(menu->mutex_img);
		mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		if (i == 100)
			i = 0;
	}
	menu->key_pressed = 0;
	return (NULL);
}

void	carelage(t_menu *menu, int frame)
{
	t_co	co;

	co.x = frame;
	co.y = 0;
	co.color = BLACK;
	co.x = frame + 1;
	co.color = CARELAGE_COLOR;
	while (co.x < WIDTH)
	{
		if (co.x < 600)
			menu_bg_line(menu->img, co, (t_co)
			{.x = ((600 - ft_abs(600 - co.x) * CARELAGE_RATIO)), .y = 900});
		else
			menu_bg_line(menu->img, co, (t_co)
			{.x = ((ft_abs(600 - co.x) * CARELAGE_RATIO) + 600), .y = 900});
		co.x += CARELAGE_LEN;
	}
}

void	put_carelage_x(t_menu *menu)
{
	t_co	co;

	co.x = 0;
	co.color = CARELAGE_COLOR;
	co.y = 30;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 100;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 200;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 330;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 490;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 680;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
}
