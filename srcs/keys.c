/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:08:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 16:38:41 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 33, 0, ft_close, cub);
	mlx_hook(cub->mlx.win, 2, 1L << 0, check_key, cub);
}

int	check_key(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	else if (key == LEFT_KEY || key == RIGHT_KEY || key == A_KEY || key == 'd'
		|| key == W_KEY || key == S_KEY)
		move_player(cub, key);
	return (0);
}

int	ft_close(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(cub->mlx.init, cub->text[i].img);
		i++;
	}
	mlx_destroy_image(cub->mlx.init, cub->mlx.img.img);
	mlx_destroy_window(cub->mlx.init, cub->mlx.win);
	mlx_destroy_display(cub->mlx.init);
	free(cub->mlx.init);
	close(cub->fd);
	free_cub(cub);
	exit(0);
	return (0);
}

void	draw_box(t_cub *cub, t_co start, t_co end)
{
	int	save;

	save = start.x;
	while (start.y < end.y)
	{
		start.x = save;
		while (start.x < end.x)
		{
			my_pixel_put(&cub->mlx.img, start.x, start.y, start.color);
			start.x++;
		}
		start.y++;
	}
}
