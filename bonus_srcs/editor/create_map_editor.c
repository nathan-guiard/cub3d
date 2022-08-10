/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_editor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:36:32 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:43:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	write_map(t_menu *menu);
static void	the_no_function(t_menu *menu);

void	draw_create_map(t_menu *menu)
{
	draw_box(menu, (t_co){.x = WIDTH / 2 - 380, .y = HEIGTH / 2 - 140,
		.color = THREE_BLUE},
		(t_co){.x = WIDTH / 2 + 380, .y = HEIGTH / 2 + 140});
	draw_box(menu, (t_co){.x = WIDTH / 2 - 375, .y = HEIGTH / 2 - 135,
		.color = BLACK},
		(t_co){.x = WIDTH / 2 + 375, .y = HEIGTH / 2 + 135});
	mlx_putstr(&menu->img, "do you want to", (t_co){.x = WIDTH / 2 - 280,
		.y = HEIGTH / 2 - 120, .color = THREE_BLUE}, 4);
	mlx_putstr(&menu->img, "create this map", (t_co){.x = WIDTH / 2 - 300,
		.y = HEIGTH / 2 - 60, .color = THREE_BLUE}, 4);
	mlx_putstr(&menu->img, menu->map_name,
		(t_co){.x = WIDTH / 2 - (15 * ft_strlen(menu->map_name)),
		.y = HEIGTH / 2 + 10, .color = 0x00ffffff}, 3);
	mlx_putstr(&menu->img, "yes", (t_co){.x = WIDTH / 2 - 220,
		.y = HEIGTH / 2 + 60, .color = GREEN}, 4);
	mlx_putstr(&menu->img, "no", (t_co){.x = WIDTH / 2 + 120,
		.y = HEIGTH / 2 + 60, .color = 0x00ff0000}, 4);
	straight_line(&menu->img, (t_co){.x = WIDTH / 2 - 225,
		.y = HEIGTH / 2 + 105, .color = GREEN}, 50, DIR_X);
	straight_line(&menu->img, (t_co){.x = WIDTH / 2 + 115,
		.y = HEIGTH / 2 + 105, .color = 0x00ff0000}, 50, DIR_X);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

void	create_map_handling(t_menu *menu, int key)
{
	if (key == 'y' || key == ENTER)
	{
		write_map(menu);
		free(menu->map_name);
		menu->map_name = NULL;
		close(menu->fd);
		draw_box(menu, (t_co){.x = 0, .y = 0, .color = 0},
			(t_co){.x = WIDTH, .y = HEIGTH});
		draw_first_menu(menu);
		menu->status = start;
	}
	if (key == 'n' || key == DEL)
		the_no_function(menu);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

static void	write_map(t_menu *menu)
{
	int	i;
	int	j;

	i = 0;
	ft_putendl_fd(MAP_COLOR_STR, menu->fd);
	ft_putstr_fd(MAP_TPATH1_STR, menu->fd);
	ft_putendl_fd(MAP_TPATH2_STR, menu->fd);
	ft_putchar_fd('\n', menu->fd);
	while (i < MAX_ROW)
	{
		j = 0;
		while (j < MAX_COL)
		{
			ft_putchar_fd(menu->char_map[i][j], menu->fd);
			j++;
		}
		ft_putchar_fd('\n', menu->fd);
		i++;
	}
}

static void	the_no_function(t_menu *menu)
{
	char	*to_free;
	char	*sub;

	draw_box(menu, (t_co){.x = 0, .y = 0, .color = 0},
		(t_co){.x = WIDTH, .y = HEIGTH});
	sub = ft_strjoin("maps/", menu->map_name);
	to_free = sub;
	sub = ft_strjoin(sub, ".cub");
	free(to_free);
	draw_editor(menu, sub);
	free(sub);
	menu->status = editor_building;
}
