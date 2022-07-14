/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:08:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/12 15:12:18 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 17, 0, ft_close, &cub->mlx);
	mlx_hook(cub->mlx.win, 2, 1L << 0, check_key, &cub->mlx);
}

int	check_key(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		ft_close(cub);
	if (keycode == UP_KEY)
		move_player(cub, keycode);
	return (0);
}

void	move_player(t_cub *cub, int keycode)
{
	if (keycode == UP_KEY)
	{
		if (ft_swap_up(cub->char_map) == -1)
			printf("hit wall\n");
		draw_mini_map(cub);
		mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, \
		cub->mlx.img.img, 0, 0);
	}
}

int	ft_swap_up(char **tab)
{
	int i;
	int	j;
	int	flag;
	char	temp;

	i = 0;
	j = 0;
	flag = 0;
	while (tab[i] && flag == 0)
	{
		i++;
		while (tab[i][j])
		{
			if (ft_isset(tab[i][j], "NSEW") == 1)
			{
				flag = 1;
				break ;
			}
			j++;
		}
	}
	if (tab[i - 1][j] != '0')
		return (-1);
	temp = tab[i][j];
	tab[i][j] = tab[i - 1][j];
	tab[i - 1][j] = temp;
	return (0);
}

int	ft_close(t_cub *cub)
{
    (void)cub;
	//free_cub(cub);
	//mlx_destroy_image(cub->mlx.init, cub->mlx.img.img);
	//mlx_destroy_window(cub->mlx.init, cub->mlx.win);
	//mlx_destroy_display(cub->mlx.init);
	//free(cub->mlx.init);
	exit(0);
	return (0);
}
