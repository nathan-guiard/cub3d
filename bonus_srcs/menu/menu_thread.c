/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:18:57 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/16 13:19:37 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	*refresh_rate(void *arg)
{
	t_menu	*menu;

	menu = (t_menu *)arg;
	while (1)
	{
		usleep(30000);
		pthread_mutex_lock(menu->mutex_img);
		mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		pthread_mutex_unlock(menu->mutex_img);
	}
}

int	animation_thread(void *arg)
{
	pthread_t	tid;
	t_menu		*menu;
	static int	test;

	if (test == 1)
		return (0);
	test = 1;
	menu = (t_menu *)arg;
	pthread_create(&tid, NULL, menu_bg_animation, menu);
	return (0);
}
