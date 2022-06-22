/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_to_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:39:12 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/31 13:21:30 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void x_diag(t_img *img, t_co co, int size);

void	ft_x(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size * 10,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y + size * 10,
		.color = co.color}, 3 * size, DIR_X);
	x_diag(img, co, size);
}

static void x_diag(t_img *img, t_co co, int size)
{
	diagonale(img, (t_co){.x = co.x + size * 3, .y = co.y,
		.color = co.color},2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + size * 8, .y = co.y + size * 5,
		.color = co.color},2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + size * 3,
		.color = co.color},2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + size * 5, .y = co.y + size * 8,
		.color = co.color},2 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x, .y = co.y + size * 7, 
		.color = co.color},2 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + size * 3, .y = co.y + size * 10, 
		.color = co.color},2 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + size * 5, .y = co.y + size * 2, 
		.color = co.color},2 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + size * 8, .y = co.y + size * 5, 
		.color = co.color},2 * size, UPSIDE);
}

void	ft_y(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 10 * size,
		.color = co.color}, 4 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 5 * size,
		.color = co.color}, 3 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + size * 7, .y = co.y + 8 * size,
		.color = co.color}, 3 * size, UPSIDE);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y + 8 * size,
		.color = co.color}, 2 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 3, .y = co.y + 8 * size,
		.color = co.color}, 2 * size, DIR_Y);
}

void	ft_z(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + size * 10, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + size * 7,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size * 7,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 7 * size,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 0 * size, .y = co.y + 3 * size,
		.color = co.color}, 5 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 6 * size, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, UPSIDE);
}
