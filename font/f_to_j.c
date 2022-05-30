/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_to_j.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:59:09 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/30 16:22:39 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_f(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color},
		10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y, .color = co.color},
		10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 4 * size,
		.color = co.color}, 5 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 8 * size, .y = co.y + 4 * size,
		.color = co.color}, 2 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
}

void	ft_g(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 2 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 3 * size,
		.color = co.color}, 7 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 2 * size,
		.color = co.color}, 6 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 5 * size,
		.color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 4 * size, .y = co.y + 2 * size,
		.color = co.color}, 5 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 8 * size, .y = co.y + 5 * size,
		.color = co.color}, 2 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 3 * size,
		.color = co.color}, 2 * size, DIR_Y);
}

void	ft_h(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 5 * size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 10 * size, DIR_Y);
}

void	ft_i(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 3 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 3 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 7 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_Y);
}

void	ft_j(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 10 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 10 * size,
		.color = co.color}, 7 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 2 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 10 * size, .y = co.y,
		.color = co.color}, 3 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 6 * size,
		.color = co.color}, 4 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x, .y = co.y + 3 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 3 * size,
		.color = co.color}, 3 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 7 * size, .y = co.y + 3 * size,
		.color = co.color}, 7 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 2 * size, .y = co.y + 6 * size,
		.color = co.color}, 1 * size, DIR_Y);
	straight_line(img, (t_co){.x = co.x + 2 * size, .y = co.y + 7 * size,
		.color = co.color}, 1 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 3 * size,
		.color = co.color}, 4 * size, DIR_Y);
}
