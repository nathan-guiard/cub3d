/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:30:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/10 22:07:07 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	start_handling(int key, t_menu *menu)
{
	if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY || key == RIGHT_KEY)
		draw_menu_button(menu, key);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
}
