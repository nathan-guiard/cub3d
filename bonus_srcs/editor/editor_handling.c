/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/13 12:03:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	editor_handling(t_menu *menu, int key)
{
	static char	*name;

	if (key == ESC)
	{
		if (menu->char_map)
			free_tabtab(menu->char_map);
		if (menu->fd != -1)
			close(menu->fd);
		ft_printf("quitte editor\n");
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		menu->status = start;
		if (name)
			free(name);
		name = NULL;
		start_handling(UP_KEY, menu);
	}
	else if (menu->status == editor_ask_name)
		name = ask_name_handling(menu, key, name);
	else if (menu->status == editor_building)
		build_handling(menu, key);
}