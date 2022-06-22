/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:09:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 15:48:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handling(int key, void *arg)
{
	t_menu	*menu;
	
	menu = (t_menu *)arg;
	ft_printf("%d\n", key);
	if (key == ESC)
		quit_everything();
	if (menu->status == start)
		start_handling(key, menu);
	return (0);
}