/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:28:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 10:42:10 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(char **tab, t_player *player)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (tab[i] && flag == 0)
	{
		i++;
		if (!tab[i])
			return (-1);
		j = 0;
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
	set_pos(tab, player, i, j);
	return (0);
}

void	set_pos(char **tab, t_player *player, int i, int j)
{
	player->dir = tab[i][j];
	player->x = (j * TILE_SIZE) + TILE_SIZE / 2;
	player->y = (i * TILE_SIZE) - TILE_SIZE / 2;
}

t_player	*init_player(t_cub *cub)
{
	t_player	*player;

	player = (t_player *)ft_calloc(sizeof(player), 3);
	if (!player)
		return (NULL);
	if (find_player(cub->char_map, player) == -1)
		ft_error_ray(cub, "ERROR: player error");
	if (player->dir == 'N')
		player->rotation_angle = 0.5 * PI;
	if (player->dir == 'E')
		player->rotation_angle = 0;
	if (player->dir == 'S')
		player->rotation_angle = (3 * PI) * 0.5;
	if (player->dir == 'W')
		player->rotation_angle = PI;
	return (player);
}
