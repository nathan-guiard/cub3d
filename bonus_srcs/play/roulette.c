/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:24:06 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/23 22:14:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	erase_play_maps(t_menu *menu, char **tab);

int roulette(t_menu *menu, t_list *lst, int key, int index)
{
    char	**last;
	char	**now;

    last = define_map_tab(lst, index);
	if (key == UP_KEY || key == RIGHT_KEY)
		index++;
	else
		index--;
	if (index < -2)
		index = -2;
	if (index > ft_lstsize(lst) + 1)
		index = ft_lstsize(lst) + 1;
	now = define_map_tab(lst, index);
	erase_play_maps(menu, last);
	put_play_maps(menu, now);
	custom_free_tabtab(now);
	custom_free_tabtab(last);
	mlx_put_image_to_window(menu->init, menu->win, menu->img.img, 0, 0);
	return (index);
}

char	**define_map_tab(t_list *lst, int index)
{
	char	**res;
	t_list	*buff;
	int		i;

	res = ft_calloc(sizeof(char *), 5);
	i = 0;
	while (i < 5)
	{
		buff = ft_lstindex(lst, index - 2 + i);
		if (buff)
			res[i] = treated_string(buff->content);
		i++;
	}
	return (res);
}

void	put_play_maps(t_menu *menu, char **tab)
{
	t_co	co;
	int		i;

	i = 0;
	co.x = 325;
	co.y = 250;
	co.color = BLACK;
	ft_printf("\n\033[1;32m");
	while (i < 5)
	{
		if (i == 2)
		{
			mlx_putstr(&menu->img, tab[i],
				(t_co){.x = co.x, .y = co.y, .color = GREEN}, 4);
		}
		else
			mlx_putstr(&menu->img, tab[i], co, 4);
		ft_printf("Put: %s\n", tab[i]);
		i++;
		co.y += 100;
	}
	ft_printf("\033[m");
}

void	erase_play_maps(t_menu *menu, char **tab)
{
	t_co	co;
	int		i;

	i = 0;
	co.x = 325;
	co.y = 250;
	co.color = 0x00002000;
	ft_printf("\n\033[1m");
	while (i < 3)
	{
		co.color += 0x00002000;
		mlx_putstr(&menu->img, tab[i], co, 4);
		ft_printf("Put: %s\n", tab[i]);
		i++;
		co.y += 100;
	}
	while (i < 5)
	{
		co.color -= 0x00002000;
		mlx_putstr(&menu->img, tab[i], co, 4);
		ft_printf("Put: %s\n", tab[i]);
		i++;
		co.y += 100;
	}
	ft_printf("\033[m");
}