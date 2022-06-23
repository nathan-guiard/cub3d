/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:36:46 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/23 19:12:01 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static t_list	*destroy_map_list(t_list *lst);

void	play_handling(t_menu *menu, int key)
{
	static t_list	*map_list;
	static int		index;

	if (!map_list)
		map_list = get_map_list();
	t_list	*test;
	test = map_list;
	while (test)
	{
		ft_putendl_fd(test->content, 1);
		test = test->next;
	}
	if (key == ESC)
	{
		menu->button = 0;
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = 0},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		remove_border(&menu->img, (t_co){.x = 400, .y = 500});
		mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		map_list = destroy_map_list(map_list);
		menu->status = start;
		index = 0;
	}
}

static t_list	*destroy_map_list(t_list *lst)
{
	ft_lstclear(&lst, free);
	return (NULL);
}