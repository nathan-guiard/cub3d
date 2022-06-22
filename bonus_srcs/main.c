/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:51:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/02 03:35:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	menu_loop(t_menu *menu)
{
	ft_printf("test\n");
	menu_bg_animation(menu);

	return (0);
}

int	main(int argc, char **argv)
{
	t_menu	menu;

	menu = init_menu(argc, argv);
	menu_hooks(&menu);
	draw_first_menu(&menu);
	//menu_bg_animation(&menu);
	
	mlx_loop_hook(menu.init, menu_loop, &menu);
	mlx_loop(menu.init);
}
