/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_to_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:49:13 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/30 19:17:50 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_p(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 9 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + size * 6,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + size * 6,
		.color = co.color}, 5 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + size * 6,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y,
		.color = co.color}, size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + size,
		.color = co.color}, size * 4, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y +  2 *size,
		.color = co.color}, size * 2, DIR_Y);
}

void	ft_q(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 9 * size,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 8 * size, .y = co.y + 9 * size,
		.color = co.color}, size * 2, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 9 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 9 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + 4 * size, .y = co.y + 8 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 7 * size, .y = co.y + 8 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 10 * size,
		.color = co.color}, size * 3, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 3.5 * size,
		.color = co.color}, size * 2, DIR_Y);
}

void	ft_r(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size * 10,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 5, .y = co.y + size * 8,
		.color = co.color}, 2 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + size * 5, .y = co.y + size * 8,
		.color = co.color}, 2 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y + size * 10,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y + size * 8,
		.color = co.color}, 2 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + size * 7, .y = co.y + size * 5,
		.color = co.color}, 3 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y + size * 5,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 6, .y = co.y + size * 1.5,
		.color = co.color}, 2 * size, DIR_Y);
}

void	ft_s(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size * 10,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 4, .y = co.y + size * 3,
		.color = co.color}, 6 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size * 7,
		.color = co.color}, 6 * size, DIR_X);
}

void	ft_t(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 3 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 3 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 10 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + size * 3,
		.color = co.color}, 7 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + size * 3,
		.color = co.color}, 7 * size, DIR_Y);
}