/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:49:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/06 16:59:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_the_square(t_menu *menu, int x, int y);

void	init_charmap(t_menu *menu)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc(sizeof(char *), MAX_ROW);
	while (i < MAX_ROW)
	{
		map[i] = ft_calloc(sizeof(char), MAX_COL);
		ft_memset(map[i], '0', MAX_COL);
		i++;
	}
	i = 0;
	while (i < MAX_ROW)
	{
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
	ft_printf("%s\n", map[0]);
	menu->char_map = map;
}

void	draw_charmap(t_menu *menu)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
	draw_box(menu, (t_co){.x = co.x, co.y,
			.color = GREEN},
			(t_co){.x = co.x + 48, .y = co.y + 48});
}

static void	draw_the_square(t_menu *menu, int x, int y)
{
	ft_printf("map[%d][%d] = %c (%d)\n", y, x, menu->char_map[y][x], menu->char_map[y][x]);
	if (menu->char_map[y][x] != '1' && menu->char_map[y][x] != '0'
		&& menu->char_map[y][x] != 'N' && menu->char_map[y][x] != 'S'
		&& menu->char_map[y][x] != 'E' && menu->char_map[y][x] != 'W')
		return ;
	if (menu->char_map[y][x] == '1')
		draw_wall_square(menu, (t_co){.x = 50 + x * 50, .y = 200 + y * 50});
	if (menu->char_map[y][x] == '0')
	{
		draw_box(menu, (t_co){.x = 51 + x * 50, .y = 201 + y * 50,
			.color = THREE_BLUE},
			(t_co){.x = 49 + (x + 1) * 50, .y = 249 + (y + 1) * 50});
	}
}