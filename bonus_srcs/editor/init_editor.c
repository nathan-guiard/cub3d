/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:36:50 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/08 18:20:08 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static char	*transform_str(char *str);
static void	write_error(char *str);
static void	write_warning(char *str);

void	init_editor(t_menu *menu, char *str)
{
	int fd;

	str = transform_str(str);
	if (access(str, F_OK) == 0)
		write_warning(str);
	fd = open(str, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		write_error(str);
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = BLACK},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		menu->status = start;
		key_handling(UP_KEY, menu);
		mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		return ;
	}
	menu->map_name = ft_substr(str, 5, ft_strlen(str) - 9);
	menu->fd = fd;
	menu->status = editor_building;
	draw_editor(menu, str);
	free(str);
}

static char	*transform_str(char *str)
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

static void	write_error(char *str)
{
	ft_putstr_fd("\033[31;1m", 1);
	ft_putstr_fd("Error: cannot create file ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[m", 1);
}

static void	write_warning(char *str)
{
	ft_putstr_fd("\033[35;3m", 1);
	ft_putstr_fd("Warning: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" already exists, overwriting...", 2);
	ft_putstr_fd("\033[m", 1);
}