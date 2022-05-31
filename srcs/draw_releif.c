/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_releif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:13:44 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/31 17:34:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_releif(t_img *img, t_co co, int size)
{
	diagonale(img, (t_co){.x = co.x - 2 * size, .y = co.y + size * 8,
		.color = co.color}, 2 * size, DOWNSIDE);
}