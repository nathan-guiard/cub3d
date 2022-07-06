/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_name_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:31:20 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/06 14:38:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static char	*put_new_str(t_menu *menu, char *str, int key);
static char	*del(t_menu *menu, char *str);

char	*ask_name_handling(t_menu *menu, int key, char *last)
{
	if (key == DEL && last != NULL)
		return (del(menu, last));
	if (key == ENTER && last != NULL && last[0] != '\0')
		return (init_editor(menu, last), NULL);
	if (!last)
		last = ft_calloc(1, 2);
	if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z')
		|| key == '.' || key == ' ' || key == '/' || key == 0
		|| (key >= '0' && key <= '9'))
		last = put_new_str(menu, last, key);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
	return (last);
}

static char	*put_new_str(t_menu *menu, char *str, int key)
{
	char	fraude[2];
	char	*curr;

	ft_bzero(fraude, 2);
	if (ft_strlen(str) == 20)
		return (str);
	mlx_putstr(&menu->img, str,
		(t_co){.x = 200, .y = 430, .color = BLACK}, 4);
	mlx_putstr(&menu->img, str,
		(t_co){.x = 201, .y = 431, .color = BLACK}, 4);
	fraude[0] = key;
	curr = ft_strjoin(str, fraude);
	ft_printf("%s\n",curr);
	mlx_putstr(&menu->img, curr,
		(t_co){.x = 200, .y = 430, .color = THREE_BLUE}, 4);
	mlx_putstr(&menu->img, curr,
		(t_co){.x = 201, .y = 431, .color = THREE_BLUE}, 4);
	free(str);
	return (curr);
}

static char	*del(t_menu *menu, char *str)
{
	mlx_putstr(&menu->img, str,
		(t_co){.x = 200, .y = 430, .color = BLACK}, 4);
	mlx_putstr(&menu->img, str,
		(t_co){.x = 201, .y = 431, .color = BLACK}, 4);
	ft_printf("delete: %c\t%s\t", str[ft_strlen(str) - 1], str);
	str[ft_strlen(str) - 1] = '\0';
	mlx_putstr(&menu->img, str,
		(t_co){.x = 200, .y = 430, .color = THREE_BLUE}, 4);
	mlx_putstr(&menu->img, str,
		(t_co){.x = 201, .y = 431, .color = THREE_BLUE}, 4);
	ft_printf("%s\n", str);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
	return (str);
}