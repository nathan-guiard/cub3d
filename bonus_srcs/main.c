/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:51:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 18:06:12 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	menu_loop(t_menu *menu)
{
	ft_printf("\n");
	menu_bg_animation(menu);

	return (0);
}

int	main(int argc, char **argv)
{
	t_menu	menu;

	usleep(1000);
	menu = init_menu(argc, argv);
	menu_hooks(&menu);
	draw_first_menu(&menu);
	mlx_put_image_to_window(menu.init, menu.win, menu.img.img, 0, 0);
	//animation_thread(&menu);
	//mlx_loop_hook(menu.init, animation_thread, &menu);
	//printf("IOAHSDPIHASIDHASHPDOIHASPDJ");
	mlx_loop(menu.init);
}
