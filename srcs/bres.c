/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:35:17 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/29 14:11:27 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bresenham(int x1, int y1, int x2, int y2, t_cub *cub)
{
	t_line	data;

	set_data(x1, y1, x2, y2, &data);
	if (data.dx > data.dy)
	{
		data.err = data.dx / 2;
		while (data.x != x2)
		{
			if (data.x == x2 - 1)
				printf("hi\n");
			my_pixel_put(&cub->mlx.img, data.x, data.y, 0xff0000);
			data.err -= data.dy;
			if (data.err < 0)
			{
				data.y += data.ym;
				data.err += data.dx;
			}
			data.x += data.xm;
		}
	}
	else
		ft_bresenham_bis(&data, cub, y2);
	my_pixel_put(&cub->mlx.img, data.x, data.y, 0xff0000);
}

void	set_data(int x1, int y1, int x2, int y2, t_line *data)
{
	data->dx = abs(x2 - x1);
	data->dy = abs(y2 - y1);
	data->x = x1;
	data->y = y1;
	if (x1 > x2)
		data->xm = -1;
	else
		data->xm = 1;
	if (y1 > y2)
		data->ym = -1;
	else
		data->ym = 1;
}

void	ft_bresenham_bis(t_line *data, t_cub *cub, int y2)
{
	data->err = data->dy / 2;
	while (data->y != y2)
	{	
		my_pixel_put(&cub->mlx.img, data->x, data->y, 0xff0000);
		data->err -= data->dx;
		if (data->err < 0)
		{
			data->x += data->xm;
			data->err += data->dy;
		}
		data->y += data->ym;
	}
}

void	ft_bresenham2(int x1, int y1, int x2, int y2, t_cub *cub)
{
	t_line	data;

	set_data2(x1, y1, x2, y2, &data);
	if (data.dx > data.dy)
	{
		data.err = data.dx / 2;
		while (data.x != x2)
		{
			my_pixel_put(&cub->mlx.img, data.x, data.y, 0xFFFF00);
			data.err -= data.dy;
			if (data.err < 0)
			{
				data.y += data.ym;
				data.err += data.dx;
			}
			data.x += data.xm;
		}
	}
	else
		ft_bresenham_bis2(&data, cub, y2);
	my_pixel_put(&cub->mlx.img, data.x, data.y, 0xFFFF00);
}

void	set_data2(int x1, int y1, int x2, int y2, t_line *data)
{
	data->dx = abs(x2 - x1);
	data->dy = abs(y2 - y1);
	data->x = x1;
	data->y = y1;
	if (x1 > x2)
		data->xm = -1;
	else
		data->xm = 1;
	if (y1 > y2)
		data->ym = -1;
	else
		data->ym = 1;
}

void	ft_bresenham_bis2(t_line *data, t_cub *cub, int y2)
{
	data->err = data->dy / 2;
	while (data->y != y2)
	{	
		my_pixel_put(&cub->mlx.img, data->x, data->y, 0xFFFF00);
		data->err -= data->dx;
		if (data->err < 0)
		{
			data->x += data->xm;
			data->err += data->dy;
		}
		data->y += data->ym;
	}
}
