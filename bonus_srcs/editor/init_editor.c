/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:36:50 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/05 12:37:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static char	*transform_last(char *str);

void	init_editor(t_menu *menu, char *last)
{
	int fd;

	last = transform_last(last);
	if (access(last, F_OK) == 0)
	{
		ft_putstr_fd("\033[35;3m", 1);
		ft_putstr_fd("Warning: ", 2);
		ft_putstr_fd(last, 2);
		ft_putendl_fd(" already exists, overwriting...", 2);
		ft_putstr_fd("\033[m", 1);
	}
	fd = open(last, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("\033[31;1m", 1);
		ft_putstr_fd("Error: cannot create file ", 2);
		ft_putendl_fd(last, 2);
		ft_putstr_fd("\033[m", 1);
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		menu->status = start;
		key_handling(UP_KEY, menu);
	}
	menu->fd = fd;
}

static char	*transform_last(char *str)
{
	char	*to_free;

	to_free = str;
	str = ft_strjoin("maps/", str);
	free(to_free);
	to_free = str;
	str = ft_strjoin(str, ".cub");
	free(to_free);
	return (str);
}