/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:53:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/11 16:47:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_menu	init_menu(int argc, char **argv)
{
	t_menu					res;
	static pthread_mutex_t	mutex;

	res.base_time = get_elapsedtime(0);
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
	res.button_co = (t_co){.x = 400, .y = 500};
	res.button = 0;
	res.key_pressed = 0;
	pthread_mutex_init(&mutex, NULL);
	res.mutex_img = &mutex;
	res.char_map = NULL;
	res.fd = -1;
	return (res);
}