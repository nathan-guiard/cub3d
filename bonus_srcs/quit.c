/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:05:36 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:06:51 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	quit_everything(t_menu *menu)
{
	mlx_destroy_image(menu->init, menu->img.img);
	mlx_destroy_window(menu->init, menu->win);
	mlx_destroy_display(menu->init);
	free(menu->init);
	exit(0);
}
