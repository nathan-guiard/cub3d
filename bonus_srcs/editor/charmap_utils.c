/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:49:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/09 11:47:57 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_the_square(t_menu *menu, int x, int y);

void	init_charmap(t_menu *menu)
{
	char	**map;
	int		i;

	i = 0;
	if (menu->char_map != NULL)
		return ;
	map = ft_calloc(sizeof(char *), MAX_ROW);
	while (i < MAX_ROW)
	{
		map[i] = ft_calloc(sizeof(char), MAX_COL);
		ft_memset(map[i], '0', MAX_COL);
		map[i][0] = '1';
		map[i][MAX_COL - 1] = '1';
		i++;
	}
	i = 0;
	while (i < MAX_COL)
	{
		map[0][i] = '1';
		map[MAX_ROW - 1][i] = '1';
		i++;
	}
	menu->char_map = map;
}

void	draw_charmap(t_menu *menu)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_box(menu, menu->button_co,
		(t_co){.x = menu->button_co.x + 50, menu->button_co.y + 50});
	draw_box(menu, (t_co){.x = menu->button_co.x + 1, menu->button_co.y + 1, .color = BLACK},
		(t_co){.x = menu->button_co.x + 49, menu->button_co.y + 49});
	while (x < MAX_COL)
	{
		y = 0;
		while (y < MAX_ROW)
		{
			draw_the_square(menu, x, y);
			y++;	
		}
		x++;
	}
}

void draw_wall_square(t_menu *menu, t_co co)
{
	draw_box(menu, (t_co){.x = co.x, .y = co.y, .color = BLACK},
			(t_co){.x = co.x + 48, .y = co.y + 48});
	straight_line(&menu->img, (t_co){.x = co.x + 4, .y = co.y + 4,
		.color = THREE_BLUE}, 40, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 4, .y = co.y + 4,
		.color = THREE_BLUE}, 40, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 44, .y = co.y + 4,
		.color = THREE_BLUE}, 40, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 4, .y = co.y + 44,
		.color = THREE_BLUE}, 40, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 4, .y = co.y + 14,
		.color = THREE_BLUE}, 40, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 4, .y = co.y + 24,
		.color = THREE_BLUE}, 40, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 4, .y = co.y + 34,
		.color = THREE_BLUE}, 40, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 14, .y = co.y + 4,
		.color = THREE_BLUE}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 34, .y = co.y + 4,
		.color = THREE_BLUE}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 24, .y = co.y + 14,
		.color = THREE_BLUE}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 14, .y = co.y + 24,
		.color = THREE_BLUE}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 34, .y = co.y + 24,
		.color = THREE_BLUE}, 10, DIR_Y);
	straight_line(&menu->img, (t_co){.x = co.x + 24, .y = co.y + 34,
		.color = THREE_BLUE}, 10, DIR_Y);
}

static void	draw_the_square(t_menu *menu, int x, int y)
{
	if (menu->char_map[y][x] != '1' && menu->char_map[y][x] != '0'
		&& menu->char_map[y][x] != 'N' && menu->char_map[y][x] != 'S'
		&& menu->char_map[y][x] != 'E' && menu->char_map[y][x] != 'W')
		return ;
	if (menu->char_map[y][x] == '1')
		draw_wall_square(menu, (t_co){.x = 51 + x * 50, .y = 201 + y * 50});
	if (menu->char_map[y][x] == 'N' || menu->char_map[y][x] == 'W' ||
		menu->char_map[y][x] == 'S' || menu->char_map[y][x] == 'E')
		draw_player(menu, menu->char_map[y][x], x, y);
	if (menu->char_map[y][x] == '0')
	{
		draw_box(menu, (t_co){.x = 51 + x * 50, .y = 201 + y * 50,
			.color = 0x00101010},
			(t_co){.x = 48 + (x + 1) * 50, .y = 199 + (y + 1) * 50});
	}
}