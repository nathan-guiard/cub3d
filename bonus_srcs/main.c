/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:51:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 17:10:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	menu_loop(t_menu *menu)
{
	ft_printf("\n");
	menu_bg_animation(menu);

	return (0);
}

int	main(int argc, char **argv)
{
	t_menu	menu;

	menu = init_menu(argc, argv);
	menu_hooks(&menu);
	draw_first_menu(&menu);
	mlx_put_image_to_window(menu.init, menu.win, menu.img.img, 0, 0);
	//animation_thread(&menu);
	//mlx_loop_hook(menu.init, animation_thread, &menu);
	//printf("IOAHSDPIHASIDHASHPDOIHASPDJ");
	mlx_loop(menu.init);
}
