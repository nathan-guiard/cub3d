/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:04:05 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 13:22:48 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	launch_cub3d(t_cub *cub)
{
	cub->mlx = init_mlx(cub);
	if (get_text(cub) == -1)
		ft_error(cub, &cub->map, "ERROR : MLX texture path error");
	if (raycasting(cub) == -1)
		return (-1);
	set_hooks(cub);
	minimap(cub);
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, \
	cub->mlx.img.img, 0, 0);
	mlx_loop(cub->mlx.init);
	return (1);
}

t_mlx	init_mlx(t_cub *cub)
{
	t_mlx	mlx;

	(void)cub;
	mlx.init = mlx_init();
	if (!mlx.init)
	{
		ft_putendl_fd("MLX init error", 2);
		free_cub(cub);
		exit(1);
	}
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGTH, "cub3d");
	if (!mlx.win)
	{
		ft_putendl_fd("MLX window error", 2);
		mlx_destroy_display(mlx.init);
		free(mlx.init);
		free_cub(cub);
		exit(1);
	}
	mlx.img.img = mlx_new_image(mlx.init, WIDTH, HEIGTH);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, \
	&mlx.img.bpp, &mlx.img.line_len, &mlx.img.endian);
	return (mlx);
}

void	my_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGTH)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
