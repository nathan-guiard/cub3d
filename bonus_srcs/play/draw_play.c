/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:35:06 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 18:27:54 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_play(t_menu *menu)
{
	draw_box(menu, (t_co){.x = 0, .y = 0, .color = 0},
		(t_co){.x = WIDTH, .y = HEIGTH});
	mlx_putstr(&menu->img, "Choose a map", (t_co){.x = 360, .y = 50, .color = GREEN}, 4);
}