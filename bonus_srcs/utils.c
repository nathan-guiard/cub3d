/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:24:32 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/12 17:24:48 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_2comp(t_img *img, t_co co, int size)
{
	straight_line(img, (t_co){.x = co.x + 6 * size, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, DIR_X);
	straight_line(img, (t_co){.x = co.x + 3 * size, .y = co.y + 3 * size,
		.color = co.color}, size, DIR_X);
	diagonale(img, (t_co){.x = co.x, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, UPSIDE);
	diagonale(img, (t_co){.x = co.x + 6 * size, .y = co.y + 7 * size,
		.color = co.color}, 4 * size, UPSIDE);
}
