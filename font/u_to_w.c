/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_to_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:18:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/30 19:38:17 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_u(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
}

void	ft_v(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 4, .y = co.y + 10 * size,
		.color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 6 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 6 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y,
		.color = co.color}, 5 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 6 * size, .y = co.y + 10 * size,
		.color = co.color}, 4 * size, UPSIDE);
}

void	ft_w2(t_img *img, t_co co, int size);

void	ft_w(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + size * 7, .y = co.y,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 1 * size, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 10 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 9 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 *size, .y = co.y,
		.color = co.color}, 9 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	ft_w2(img, co, size);
}

void	ft_w2(t_img *img, t_co co, int size)
{
	diagonale(img, (t_co){.x = co.x, .y = co.y + 9 * size,
		.color = co.color}, 1 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 5 * size, .y = co.y + 9 * size,
		.color = co.color}, 1 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 4 * size, .y = co.y + 10 * size,
		.color = co.color}, 1 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 10 * size,
		.color = co.color}, 1 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 6 * size, .y = co.y + 2 * size,
		.color = co.color}, 1 * size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 3 * size, .y = co.y + 3 * size,
		.color = co.color}, 1 * size, UPSIDE);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 2 * size,
		.color = co.color}, 2 * size, DIR_X);
}