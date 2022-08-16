/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:09:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/16 12:02:43 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	escape_function(t_menu *menu, char *name);

void	editor_handling(t_menu *menu, int key)
{
	static char	*name;

	if (key == ESC)
	{
		if (menu->char_map != NULL)
		{
			free_tabtab(menu->char_map);
			menu->char_map = NULL;
		}
		escape_function(menu, name);
	}
	else if (menu->status == editor_ask_name)
		name = ask_name_handling(menu, key, name);
	else if (menu->status == editor_building)
		build_handling(menu, key);
	else if (menu->status == editor_create_map)
		create_map_handling(menu, key);
}

static void	escape_function(t_menu *menu, char *name)
{
	if (menu->fd != -1)
		close(menu->fd);
	draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
		(t_co){.x = WIDTH, .y = HEIGTH});
	draw_first_menu(menu);
	menu->status = start;
	if (name)
		free(name);
	name = NULL;
	if (menu->map_name != 0)
		free(menu->map_name);
	menu->map_name = NULL;
	start_handling(UP_KEY, menu);
}
