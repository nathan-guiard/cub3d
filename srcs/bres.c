/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:35:17 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/07 17:40:10 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bresenham(t_cords *cords, t_cub *cub)
{
	t_line	data;

	set_data(cords, &data);
	if (data.dx > data.dy)
	{
		data.err = data.dx / 2;
		while (data.x != cords->x2)
		{
			if (data.x == cords->x2 - 1)
				printf("hi\n");
			my_pixel_put(&cub->mlx.img, data.x, data.y, cub->c_color);
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
		ft_bresenham_bis(cords, cub, &data);
	my_pixel_put(&cub->mlx.img, data.x, data.y, cub->c_color);
}

void	set_data(t_cords *cords, t_line *data)
{
	data->dx = abs(cords->x2 - cords->x1);
	data->dy = abs(cords->y2 - cords->y1);
	data->x = cords->x1;
	data->y = cords->y1;
	if (cords->x1 > cords->x2)
		data->xm = -1;
	else
		data->xm = 1;
	if (cords->y1 > cords->y2)
		data->ym = -1;
	else
		data->ym = 1;
}

void	ft_bresenham_bis(t_cords *cords, t_cub *cub, t_line *data)
{
	data->err = data->dy / 2;
	while (data->y != cords->y2)
	{	
		my_pixel_put(&cub->mlx.img, data->x, data->y, cub->c_color);
		data->err -= data->dx;
		if (data->err < 0)
		{
			data->x += data->xm;
			data->err += data->dy;
		}
		data->y += data->ym;
	}
}
