/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:06:20 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_a(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + size, .y = co.y, .color = co.color}, 8 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x, .y = co.y + size, .color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + (9 * size), .y = co.y, .color = co.color}, size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x + (10 * size), .y = co.y + size, .color = co.color}, 9 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + size, .color = co.color}, 9 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + (10 * size), .color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 5 * size, .color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 2.5 * size, .color = co.color}, 2 * size, DIR_X);
}

void	ft_b(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 9 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size, .color = co.color}, 9 * size, DIR_X);
	diagonale(img, (t_co){.x = co.x + (9 * size), .y = co.y, .color = co.color}, size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + (9 * size), .y = co.y + 5 * size, .color = co.color}, size, DOWNSIDE);
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + (10 * size), .y = co.y + size, .color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + (10 * size), .y = co.y +  6 *size, .color = co.color}, 3 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + (5 * size), .color = co.color}, size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + (9 * size), .y = co.y + 10 * size, .color = co.color}, size, UPSIDE);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 5 * size, .color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 2.5 *size, .color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 7.5 *size, .color = co.color}, 2 * size, DIR_X);
}

void	ft_c(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size, .color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y, .color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 5 * size, .color = co.color}, 5 * size, DIR_X);
}

void	ft_d(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 9 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size, .color = co.color}, 9 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + size, .color = co.color}, 8 * size, DIR_Y);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y, .color = co.color}, size, DOWNSIDE);
	diagonale(img, (t_co){.x = co.x + 9 * size, .y = co.y + 10 * size, .color = co.color}, size, UPSIDE);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 4 * size, .color = co.color}, 2 * size, DIR_Y);
}

void	ft_e(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size, .color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y, .color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 7 * size, .color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 8 * size, .y = co.y + 4 * size, .color = co.color}, 2 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 3 * size, .color = co.color}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size, .color = co.color}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 4 * size, .color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size, .color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 7 * size, .color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 3 * size, .color = co.color}, 5 * size, DIR_X);
}
