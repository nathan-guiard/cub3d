/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:28:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/09 14:57:17 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(char **tab, t_player *player, t_cub *cub)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	(void)cub;
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
	player->dir = tab[i][j];
 	player->x = (j * TILE_SIZE) + TILE_SIZE / 2;
	player->y = (i * TILE_SIZE) - 16; 
/* 	player->x = (cub->width * TILE_SIZE)/ 2;
	player->y = (cub->height * TILE_SIZE) / 2; */
	return (0);
}

t_player	*init_player(t_cub *cub)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(player) * 3);
	if (!player)
		return (NULL);
	if (find_player(cub->char_map, player, cub) == -1)
		ft_error_ray(cub, "ERROR: player error");
	if (player->dir == 'N')
		player->rotation_angle = PI / 2;
	if (player->dir == 'E')
		player->rotation_angle = 0;
	if (player->dir == 'S')
		player->rotation_angle = (3 * PI) * 0.5;
	if (player->dir == 'W')
		player->rotation_angle = PI;
	return (player);
}
