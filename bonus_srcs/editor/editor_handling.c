/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/04 18:48:37 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	editor_handling(t_menu *menu, int key)
{
	if (key == ESC)
	{
		free_tabtab(menu->char_map);
		if (menu->fd != 0)
			close(menu->fd);
		ft_printf("quitte editor\n");
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		menu->status = start;
		start_handling(UP_KEY, menu);
	}
	// if (menu->status == editor_ask_name)
	// 	ask_name_handling(menu, key);
	
}