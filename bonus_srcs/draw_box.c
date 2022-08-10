/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:09:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:06:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_box(t_menu *menu, t_co start, t_co end)
{
	int	save;

	save = start.x;
	while (start.y < end.y)
	{
		start.x = save;
		while (start.x < end.x)
		{
			my_pixel_put(&menu->img, start.x, start.y, start.color);
			start.x++;
		}
		start.y++;
	}
}
