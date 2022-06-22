/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:59:38 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	menu_hooks(t_menu *menu)
{
	mlx_hook(menu->win, 33, 0, quit_everything, menu);
	mlx_key_hook(menu->win, key_handling, menu);
}