/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:08:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/09 15:35:43 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 17, 0, ft_close, &cub->mlx);
	mlx_hook(cub->mlx.win, 2, 1L << 0, check_key, cub);
}

int	check_key(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	else if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY
		|| key == RIGHT_KEY)
		move_player(cub, key);
	return (0);
}

void	move_player(t_cub *cub, int key)
{
	draw_box(cub, (t_co){.x = 0, .y = 0, .color = BLACK},
		(t_co){.x = WIDTH, .y = HEIGTH});
	if (key == UP_KEY)
	{
		cub->player->x += 5;
	}
	raycasting(cub);
}

int	ft_close(t_cub *cub)
{
    (void)cub;
	//free_cub(cub);
	//mlx_destroy_image(cub->mlx.init, cub->mlx.img.img);
	//mlx_destroy_window(cub->mlx.init, cub->mlx.win);
	//mlx_destroy_display(cub->mlx.init);
	//free(cub->mlx.init);
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
			my_pixel_put(cub->mlx.img.img, start.x, start.y, start.color);
			start.x++;
		}
		start.y++;
	}
}