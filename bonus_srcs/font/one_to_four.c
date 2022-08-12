/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:23:23 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/12 17:27:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_1(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 10 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 10 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 3 * size,
		.color = co.color}, 7 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 5 * size,
		.color = co.color}, 5 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 4 * size, .y = co.y + 5 * size,
		.color = co.color}, 2 * size, UPSIDE);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 5 * size,
		.color = co.color}, 4 * size, DIR_X);
}

void		ft_2comp(t_img *img, t_co co, int size);

void	ft_2(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + size, .y = co.y,
		.color = co.color}, 8 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 4 * size,
		.color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y + size,
		.color = co.color}, 2 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x, .y = co.y + size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 2 * size, .y = co.y + 4 * size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + size * 9, .y = co.y,
		.color = co.color}, size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + size * 7,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size * 7,
		.color = co.color}, 3 * size, DIR_Y);
	ft_2comp(img, co, size);
}

static void	ft_3comp(t_img *img, t_co co, int size);

void	ft_3(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + 1 * size, .y = co.y,
		.color = co.color}, 9 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 1 * size,
		.color = co.color}, 1 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 9 * size,
		.color = co.color}, 1 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 4 * size,
		.color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 1 * size, .y = co.y + 10 * size,
		.color = co.color}, 9 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x + 2 * size, .y = co.y + 6 * size,
		.color = co.color}, 1 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 1 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 3 * size, DIR_Y);
	ft_3comp(img, co, size);
}

static void	ft_3comp(t_img *img, t_co co, int size)
{
	diagonale(img, (t_co){.x = co.x + 2 * size, .y = co.y + 4 * size,
		.color = co.color}, 1 * size, UPSIDE);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 3 * size,
		.color = co.color}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 6 * size,
		.color = co.color}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 4 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 6 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 4 * size,
		.color = co.color}, 2 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
}

void	ft_4(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 10 * size,
		.color = co.color}, 6 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 5 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 5 * size,
		.color = co.color}, 5 * size, DIR_Y);
}
