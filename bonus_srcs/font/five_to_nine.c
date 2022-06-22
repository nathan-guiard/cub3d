/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_to_nine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:48:04 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/31 14:14:29 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_5(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 8 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 5 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 5 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 8 * size,
		.color = co.color}, 2 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + 8 * size, .y = co.y + 10 * size,
		.color = co.color}, 2 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 8 * size, .y = co.y + 3 * size,
		.color = co.color}, 2 * size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 0 * size, .y = co.y + 5 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 0 * size, .y = co.y + 8 * size,
		.color = co.color}, 3 * size, DIR_X);
}

void	ft_6(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 4 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size,
		.color = co.color}, 2 * size, DIR_Y);
}

void	ft_7(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 10 * size,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 6 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 4 * size,
		.color = co.color}, 2 * size, DIR_Y);
}

void	ft_8(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 0 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 5 * size,
		.color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 4 * size,
		.color = co.color}, size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 5 * size,
		.color = co.color}, size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 2 * size,
		.color = co.color}, size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 7 * size,
		.color = co.color}, size, DIR_Y);
}

void	ft_9(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 2 * size,
		.color = co.color}, 2 * size, DIR_Y);
}