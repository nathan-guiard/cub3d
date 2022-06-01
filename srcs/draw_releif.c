/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_releif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:13:44 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/01 17:34:42 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_releif(t_img *img, t_co co, int size)
{
	diagonale(img, (t_co){.x = co.x - 2 * size, .y = co.y + size * 8,
		.color = co.color}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x -2 * size, .y = co.y - 2 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 8 * size, .y = co.y - 2 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 18 * size, .y = co.y - 2 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 27 * size, .y = co.y - 2 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 28 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 31 * size, .y = co.y + 8 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 38 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 48 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 49 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 57 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 58 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 61 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 65 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 68 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 77 * size, .y = co.y - 2 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x - 2 * size, .y = co.y - 2 * size,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x - 2 * size, .y = co.y - 2 * size,
		.color = co.color}, 29 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 28 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 20 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 49 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 8 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 58 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 65 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 68 * size, .y = co.y - 2 * size,
		.color = co.color}, 9 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 65 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 58 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 49 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 28 * size, .y = co.y - 2 * size,
		.color = co.color + THREE_DIFF}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 31 * size, .y = co.y + 3 * size,
		.color = co.color + THREE_DIFF}, 5 * size, DIR_Y);
}