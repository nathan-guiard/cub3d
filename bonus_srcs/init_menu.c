/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:53:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 16:44:36 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_menu	init_menu(int argc, char **argv)
{
	t_menu	res;
	static pthread_mutex_t	mutex;

	res.argc = argc;
	res.argv = argv;
	res.init = mlx_init();
	res.win = mlx_new_window(res.init, WIDTH, HEIGTH, "cub_tron_d");
	res.img.img = mlx_new_image(res.init, WIDTH, HEIGTH);
	res.img.addr = mlx_get_data_addr(res.img.img, &res.img.bpp, &res.img.line_len, 
		&res.img.endian);
	if (argv && argv[1])
		res.basemap = argv[1];
	res.status = start;
	res.last_button = (t_co){.x = 400, .y = 500};
	res.button = 0;
	res.key_pressed = 0;
	pthread_mutex_init(&mutex, NULL);
	res.mutex_img = &mutex;
	return (res);
}