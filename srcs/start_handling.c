/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:30:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/29 18:46:28 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_handling(int key, t_menu *menu)
{
	if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY || key == RIGHT_KEY)
		draw_button(menu, key);
}