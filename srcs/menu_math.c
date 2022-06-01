/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:03:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/01 21:37:26 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_math	init_mathline(t_set set)
{
	t_math	all;

	all.dx = abs(set.b.x - set.a.x);
	all.sx = -1;
	if (set.a.x < set.b.x)
		all.sx = 1;
	all.dy = -abs(set.b.y - set.a.y);
	all.sy = -1;
	if (set.a.y < set.b.y)
		all.sy = 1;
	all.err = all.dx + all.dy;
	return (all);
}

t_co	base_set(t_set set)
{
	t_co	base;

	base.x = 0;
	if (set.a.x > set.b.x)
		base.x = 1;
	else if (set.a.x < set.b.x)
		base.x = -1;
	base.y = 0;
	if (set.a.y > set.b.y)
		base.y = 1;
	else if (set.a.y < set.b.y)
		base.y = -1;
	return (base);
}

int	check_base(t_set set, t_co base)
{
	if (base.x == -1 && set.a.x - set.b.x > 0)
		return (1);
	if (base.x == 1 && set.a.x - set.b.x < 0)
		return (1);
	if (base.x == 0 && set.a.x - set.b.x != 0)
		return (1);
	if (base.y == -1 && set.a.y - set.b.y > 0)
		return (1);
	if (base.y == 1 && set.a.y - set.b.y < 0)
		return (1);
	if (base.y == 0 && set.a.y - set.b.y != 0)
		return (1);
	return (0);
}