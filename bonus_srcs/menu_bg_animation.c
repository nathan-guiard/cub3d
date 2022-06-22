/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bg_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:18:36 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/02 04:22:20 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	carelage(t_menu *menu, int frame);
void	put_carelage_x(t_menu *menu);

void	menu_bg_animation(t_menu *menu)
{
	static int	i = 0;

	menu->key_pressed = 0;
	while (menu->key_pressed != 1)
	{
		i++;
		//ft_printf("%d\t\t\t%d\n", i, frame);
		if (i / ANIM_LOOP == (i - 1) / ANIM_LOOP)
		{
			carelage(menu, i / ANIM_LOOP);
			put_carelage_x(menu);
			//draw_menu(menu);
			mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
		}
		if (i == 100 * ANIM_LOOP)
			i = 0;
	}
}

void	carelage(t_menu *menu, int frame)
{
	t_co	co;

	co.x = frame;
	co.y = 0;
	co.color = BLACK;
	while (co.x < WIDTH)
	{
		if (co.x < 600)
			menu_bg_line(menu->img, co, (t_co)
				{.x = ((600 - ft_abs(600 - co.x) * CARELAGE_RATIO)), .y = 900});
		else
			menu_bg_line(menu->img, co, (t_co)
				{.x = ((ft_abs(600 - co.x) * CARELAGE_RATIO) + 600), .y = 900});
		co.x += CARELAGE_LEN;
	}
	co.x = frame + 1;
	co.color = MENU_COLOR + THREE_DIFF - SHADOW_DIFF;
	while (co.x < WIDTH)
	{
		if (co.x < 600)
			menu_bg_line(menu->img, co, (t_co)
				{.x = ((600 - ft_abs(600 - co.x) * CARELAGE_RATIO)), .y = 900});
		else
			menu_bg_line(menu->img, co, (t_co)
				{.x = ((ft_abs(600 - co.x) * CARELAGE_RATIO) + 600), .y = 900});
		co.x += CARELAGE_LEN;
	}
}

void	put_carelage_x(t_menu *menu)
{
	t_co	co;

	co.x = 0;
	co.color = MENU_COLOR + THREE_DIFF - SHADOW_DIFF;
	co.y = 30;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 100;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 200;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 330;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 490;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	co.y = 680;
	menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	//co.y = 730;
	//menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
	//co.y = 900;
	//menu_bg_line(menu->img, co, (t_co){.x = WIDTH, .y = co.y});
}