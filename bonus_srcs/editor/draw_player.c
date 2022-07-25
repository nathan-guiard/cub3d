/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:27:58 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/12 18:28:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_north(t_menu *menu, int x, int y);

void	draw_player(t_menu *menu, char key, int x, int y)
{
	if (key == 'N')
		draw_north(menu, x, y);
	// else if (key == 'E')
	// 	draw_east(menu, x, y);
	// else if (key == 'S')
	// 	draw_south(menu, x, y);
	// else
	// 	draw_west(menu, x, y);
}

static void	draw_north(t_menu *menu, int x, int y)
{
	t_co	co;

	co = (t_co){.x = 50 + (x * 50), .y = 200 + (y * 50), .color = PLAYER_COLOR};
	mlx_putstr(&menu->img, "N", (t_co){.x =co.x + 5, .y = co.y + 5,
		.color = PLAYER_COLOR}, 1);
	straight_line(&menu->img, (t_co){.x = co.x + 5, .y = co.y + 20,
		.color = PLAYER_COLOR}, 20, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 5, .y = co.y + 30,
		.color = PLAYER_COLOR}, 20, DIR_X);
	straight_line(&menu->img, (t_co){.x = co.x + 5, .y = co.y + 20,
		.color = PLAYER_COLOR}, 10, DIR_Y);
	
}