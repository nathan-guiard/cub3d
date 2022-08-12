/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:10:52 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/12 18:38:40 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	recast_img(t_cub *cub);
static void	hit_wall(t_cub *cub, float x, float y);
static void	movements(t_cub *cub, int key);

void	move_player(t_cub *cub, int key)
{	
	if (key == A_KEY || key == S_KEY || key == D_KEY
		|| key == W_KEY)
		movements(cub, key);
	else if (key == LEFT_KEY)
		cub->player->rotation_angle += PI_DIV_16;
	else if (key == RIGHT_KEY)
		cub->player->rotation_angle -= PI_DIV_16;
	recast_img(cub);
}

static void	movements(t_cub *cub, int key)
{
	if (key == W_KEY)
	{
		hit_wall(cub, cub->player->x
			+ cos(cub->player->rotation_angle) * 5, cub->player->y
			- sin(cub->player->rotation_angle) * 5);
	}
	else if (key == S_KEY)
	{
		hit_wall(cub, cub->player->x
			- cos(cub->player->rotation_angle) * 5, cub->player->y
			+ sin(cub->player->rotation_angle) * 5);
	}
	else if (key == A_KEY)
	{
		hit_wall(cub, cub->player->x
			- cos(cub->player->rotation_angle - PI_DIV_TWO) * 5, cub->player->y
			+ sin(cub->player->rotation_angle - PI_DIV_TWO) * 5);
	}
	else if (key == D_KEY)
	{
		hit_wall(cub, cub->player->x
			- cos(cub->player->rotation_angle + PI_DIV_TWO) * 5, cub->player->y
			+ sin(cub->player->rotation_angle + PI_DIV_TWO) * 5);
	}
}

static void	recast_img(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.init, cub->mlx.img.img);
	cub->mlx.img.img = mlx_new_image(cub->mlx.init, WIDTH, HEIGTH);
	cub->mlx.img.addr = mlx_get_data_addr(cub->mlx.img.img, \
	&cub->mlx.img.bpp, &cub->mlx.img.line_len, &cub->mlx.img.endian);
	cast_all_rays(cub, cub->player);
	minimap(cub);
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win,
		cub->mlx.img.img, 0, 0);
}

static void	hit_wall(t_cub *cub, float x, float y)
{
	if (cub->char_map[(int)y / TILE_SIZE + 1][(int)x / TILE_SIZE] != '1')
	{
		cub->player->x = x;
		cub->player->y = y;
	}
}
