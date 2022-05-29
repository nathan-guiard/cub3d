/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:53:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/29 11:59:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_menu	init_menu(int argc, char **argv)
{
	t_menu	res;

	res.argc = argc;
	res.argv = argv;
	res.init = mlx_init();
	res.win = mlx_new_window(res.init, WIDTH, HEIGTH, "cub3d");
	if (argv && argv[1])
		res.basemap = argv[1];
	res.status = start;
	return (res);
}