/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_dot_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:14:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:25:32 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_0(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_Y);
}

void	ft_dot(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size + 3 * size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
}

void	ft_slash(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 7 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 3 * size, .y = co.y + 10 * size,
		.color = co.color}, 7 * size, UPSIDE);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 0 * size,
		.color = co.color}, 3 * size, DIR_Y);
}
