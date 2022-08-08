/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:41:47 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/08 17:16:04 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	charmap_player_handling(t_menu *menu, int key);
static void	replace_old_player(t_menu *menu);

static void	move_cursor(t_menu *menu, int key)
{
	draw_box(menu, (t_co){.x = menu->button_co.x, menu->button_co.y,
		.color = THREE_BLUE - SHADOW_DIFF},
		(t_co){.x = menu->button_co.x + 51, menu->button_co.y + 51});
	draw_box(menu, (t_co){.x = menu->button_co.x + 1,
		menu->button_co.y + 1, .color = BLACK},
		(t_co){.x = menu->button_co.x + 50, menu->button_co.y + 50});
	if (key == UP_KEY && menu->button_co.y > 200)
		menu->button_co.y -= 50;
	if (key == DOWN_KEY && menu->button_co.y < HEIGTH - 101)
		menu->button_co.y += 50;
	if (key == RIGHT_KEY && menu->button_co.x < WIDTH - 101)
		menu->button_co.x += 50;
	if (key == LEFT_KEY && menu->button_co.x > 50)
		menu->button_co.x -= 50;		
}

void	build_handling(t_menu *menu, int key)
{
	if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY || key == RIGHT_KEY)
		move_cursor(menu, key);
	else if (key == 'q')
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = '1';
	else if (key == W_KEY || key == D_KEY || key == S_KEY || key == A_KEY)
	{
		replace_old_player(menu);
		charmap_player_handling(menu, key);
	}
	else if (key == DEL)
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = '0';
	draw_charmap(menu);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}

static void	charmap_player_handling(t_menu *menu, int key)
{
	if (key == W_KEY)
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = 'N';
	else if (key == D_KEY)
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = 'E';
	else if (key == S_KEY)
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = 'S';
	else if (key == A_KEY)
		menu->char_map[(menu->button_co.y - 200) / 50][(menu->button_co.x - 50) / 50] = 'W';
}

static void	replace_old_player(t_menu *menu)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < MAX_ROW)
	{
		j = 0;
		while (j < MAX_COL)
		{
			c = menu->char_map[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
				menu->char_map[i][j] = '0';
			j++;
		}
		i++;
	}
}