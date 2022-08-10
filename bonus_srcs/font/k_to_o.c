/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_to_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:21:31 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:23:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_k(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y + 5 * size,
		.color = co.color}, 5 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 4 * size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 4 * size,
		.color = co.color}, size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + size * 8, .y = co.y + 4 * size,
		.color = co.color}, 1 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 6, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 6, .y = co.y,
		.color = co.color}, 1 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + 5 * size, .y = co.y + 2 * size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size,
		.color = co.color}, size, DOWNSIDE);
}

void	ft_l(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 4, .y = co.y,
		.color = co.color}, 6 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 4, .y = co.y + size * 6,
		.color = co.color}, 6 * size, DIR_X);
}

void	ft_m(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 6, .y = co.y,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 3, .y = co.y + size * 6,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y + size * 6,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 3, .y = co.y + size * 6,
		.color = co.color}, 4 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x + 4 * size, .y = co.y,
		.color = co.color}, size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 5 * size, .y = co.y + size,
		.color = co.color}, size, UPSIDE);
}

void	ft_n(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x + size * 3, .y = co.y,
		.color = co.color}, 4 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + size * 3, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y,
		.color = co.color}, 4 * size, DIR_Y);
}

void	ft_o(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + size, .y = co.y,
		.color = co.color}, 8 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size, .y = co.y + 10 * size,
		.color = co.color}, 8 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size,
		.color = co.color}, 8 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + size,
		.color = co.color}, 8 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + size * 9, .y = co.y,
		.color = co.color}, size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + size * 9,
		.color = co.color}, size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 10 * size,
		.color = co.color}, size, UPSIDE);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 4 * size,
		.color = co.color}, 2 * size, DIR_Y);
}
