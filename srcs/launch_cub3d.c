/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:04:05 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/07 09:49:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	launch_cub3d(t_cub *cub)
{
	int		img_width;
	int		img_height;

	print_map(cub);
	cub->mlx = init_mlx(cub);
	my_pixel_put(&cub->mlx.img, 50, 50, cub->f_color);
	cub->mlx.img.img = mlx_png_file_to_image(cub->mlx.init, cub->s_path, \ 
	&img_width, &img_height);
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, \
	cub->mlx.img.img, 0, 0);
	mlx_loop(cub->mlx.init);
	return (1);
}

t_mlx	init_mlx(t_cub *cub)
{
	t_mlx	mlx;

	(void)cub;
/* 	mlx = ft_calloc(sizeof(mlx), 1);
	if (!mlx)
		ft_error_cub(cub, &cub->map, "malloc error"); */
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGTH, "cub3d");
	mlx.img.img = mlx_new_image(mlx.init, WIDTH, HEIGTH);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, \
	&mlx.img.bpp, &mlx.img.line_len, &mlx.img.endian);
	return (mlx);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_map(t_cub *cub)
{
	int	i;

	i = 0;
	printf("\n\033[1m\033[35m		PATHS			\033[0m\n");
	printf("NORTH : %s\n", cub->n_path);
	printf("SOUTH : %s\n", cub->s_path);
	printf("EAST : %s\n", cub->e_path);
	printf("WEST : %s\n", cub->w_path);
	printf("\n\033[1m\033[35m		COLORS			\033[0m\n");
	printf("F is %x\n", cub->f_color);
	printf("C is %x\n", cub->c_color);
	printf("\n\033[1m\033[35m		MAP			\033[0m\n");
	while (cub->char_map[i])
	{
		printf("%s\n", cub->char_map[i]);
		i++;
	}
	printf("\n\033[1m\033[35m		MAP DATA		\033[0m\n");
	printf("HEIGHT : %d\n", cub->height);
	printf("WIDTH : %d\n", cub->width);
}
