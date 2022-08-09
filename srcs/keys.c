/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:08:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/09 16:31:25 by clmurphy         ###   ########.fr       */
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
	else if (key == LEFT_KEY || key == RIGHT_KEY || key == A_KEY || key == 'd'
		|| key == W_KEY || key == S_KEY)
		move_player(cub, key);
	return (0);
}

void	move_player(t_cub *cub, int key)
{
	draw_box(cub, (t_co){.x = 0, .y = 0, .color = BLACK},
		(t_co){.x = WIDTH, .y = HEIGTH});
	if (key == W_KEY)
		cub->player->y -= 5;
	if (key == S_KEY)
		cub->player->y += 5;
	if (key == A_KEY)
		cub->player->x -= 5;
	if (key == D_KEY)
		cub->player->x += 5;
	if (key == LEFT_KEY)
		cub->player->rotation_angle += PI_DIV_16;
	if (key == RIGHT_KEY)
		cub->player->rotation_angle -= PI_DIV_16;
	draw_mini_map(cub);
	cast_all_rays(cub, cub->player);
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win,
		cub->mlx.img.img, 0, 0);
}

int	ft_close(t_cub *cub)
{
    (void)cub;
	free_cub(cub);
	mlx_destroy_image(cub->mlx.init, cub->mlx.img.img);
	mlx_destroy_window(cub->mlx.init, cub->mlx.win);
	mlx_destroy_display(cub->mlx.init);
	free(cub->mlx.init);
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