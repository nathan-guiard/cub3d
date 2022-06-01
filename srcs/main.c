/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:51:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/01 21:52:32 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_menu	menu;

	menu = init_menu(argc, argv);
	menu_hooks(&menu);
	draw_first_menu(&menu);
	//menu_bg_animation(&menu);
	menu_bg_line(menu.img, (t_co){.x = 900, .y = 0,
		.color = 0x00ffff00}, (t_co){.x = 500, .y = 900});
	mlx_put_image_to_window(menu.init, menu.win, menu.img.img, 0, 0);
	mlx_loop(menu.init);
}
