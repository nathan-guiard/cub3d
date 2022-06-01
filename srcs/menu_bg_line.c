/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bg_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:53:56 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/01 21:58:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line(t_img img, t_set set, t_math all);

void	menu_bg_line(t_img img, t_co start, t_co end)
{
	t_math	all;
	t_set	set;

	set.a = start;
	set.b = end;
	all = init_mathline(set);
	put_line(img, set, all);
}

int	is_pos_ok(t_set set)
{
	if ((set.a.x == set.b.x && set.a.y == set.b.y) || (set.a.x > WIDTH
		&& set.b.x > WIDTH) || (set.a.y > HEIGTH && set.b.y > HEIGTH))
		return (0);;
	if ((set.a.x < 0 && set.b.x < 0) || (set.a.y < 0 && set.b.y < 0)
		|| (set.a.x > WIDTH || set.a.y > HEIGTH)
		|| ((set.a.x >= TITLE_X && set.a.x <= TITLE_X + 800)
		&& (set.a.y >= TITLE_Y - 20 && set.a.y <= TITLE_Y + 100))
		|| ((set.a.x >= 400 && set.a.x <= 800) && ((set.a.y >= 250
		&& set.a.y <= 450) || (set.a.y >= 500 && set.a.y <= 700))))
		return (2);
	return (1);
}

void	put_line(t_img img, t_set set, t_math all)
{
	t_co	base;

	base = base_set(set);
	while (check_base(set, base) == 0)
	{
		if (is_pos_ok(set) == 1)
			my_pixel_put(&img, set.a.x, set.a.y, set.a.color);
		all.e2 = 2 * all.err;
		if (all.e2 >= all.dy)
		{
			all.err += all.dy;
			set.a.x += all.sx;
		}
		if (all.e2 <= all.dx)
		{
			all.err += all.dx;
			set.a.y += all.sy;
		}
	}
}
