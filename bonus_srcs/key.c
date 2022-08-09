/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:09:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/09 13:23:11 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	key_handling(int key, void *arg)
{
	t_menu			*menu;
	
	menu = (t_menu *)arg;
	ft_printf("%d\n", key);
	if (key == ESC && menu->status == start)
		quit_everything(menu);
	if (menu->status == start)
		start_handling(key, menu);
	else if (menu->status == play)
		play_handling(menu, key);
	else if (menu->status >= editor)
		editor_handling(menu, key);
	return (0);
}