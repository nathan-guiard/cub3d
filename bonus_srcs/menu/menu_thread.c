/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:18:57 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:33 by nguiard          ###   ########.fr       */
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
		printf("\t\tREFRESH\n");
		pthread_mutex_lock(menu->mutex_img);
		mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		pthread_mutex_unlock(menu->mutex_img);
	}
}

int	animation_thread(void *arg)
{
	pthread_t	tid;
	//pthread_t	tid2;
	t_menu		*menu;
	static int	test;

	if (test == 1)
		return (0);
	test = 1;
	menu = (t_menu *)arg;
	pthread_create(&tid, NULL, menu_bg_animation, menu);
	//pthread_create(&tid2, NULL, refresh_rate, menu);
	return (0);
}
