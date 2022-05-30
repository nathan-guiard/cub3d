/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straight_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:02:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/30 15:10:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	straight_line(t_img *img, t_co start, int len, int direction)
{
	int	end_x;
	int	end_y;

	end_x = start.x;
	end_y = start.y;
	if (direction == DIR_X)
		end_x += len;
	else
		end_y += len;
	while (end_x >= start.x && end_y >= start.y && start.x < WIDTH && start.y < HEIGTH)
	{
		my_pixel_put(img, start.x, start.y, start.color);
		if (direction == DIR_X)
			start.x++;
		else
			start.y++;
	}
}

void	diagonale(t_img *img, t_co start, int len, int direction)
{
	int	end_x;

	end_x = start.x + len;
	while (end_x > start.x && (start.x < WIDTH && start.y < HEIGTH) && direction == DOWNSIDE)
	{
		my_pixel_put(img, start.x, start.y, start.color);
		start.x++;
		start.y++;
	}
	while (end_x > start.x && (start.x < WIDTH && start.y < HEIGTH) && direction == UPSIDE)
	{
		my_pixel_put(img, start.x, start.y, start.color);
		start.x++;
		start.y--;
	}
}