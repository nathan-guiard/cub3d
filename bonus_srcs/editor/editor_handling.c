/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/05 12:06:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	editor_handling(t_menu *menu, int key)
{
	static char	*name;

	if (key == ESC)
	{
		free_tabtab(menu->char_map);
		if (menu->fd != -1)
			close(menu->fd);
		ft_printf("quitte editor\n");
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		menu->status = start;
		free(name);
		name = NULL;
		start_handling(UP_KEY, menu);
	}
	else if (menu->status == editor_ask_name)
		name = ask_name_handling(menu, key, name);
	// if (menu->status == editor_ask_name)
	// 	ask_name_handling(menu, key);
	
}