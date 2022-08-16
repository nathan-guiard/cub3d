/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:51:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/16 11:46:08 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_menu	menu;

	menu = init_menu(argc, argv, env);
	menu_hooks(&menu);
	draw_first_menu(&menu);
	mlx_put_image_to_window(menu.init, menu.win, menu.img.img, 0, 0);
	mlx_loop(menu.init);
}
