/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:28:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/25 14:22:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	*find_player(char **tab)
{
	int		i;
	int		j;
	int		flag;
	t_pos	*pos;

	i = 0;
	j = 0;
	flag = 0;
	pos = malloc(sizeof(t_pos *));
	if (!pos)
		return (NULL);
	while (tab[i] && flag == 0)
	{
		i++;
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
	pos->x = (j * TILE_SIZE) + TILE_SIZE / 2;
	pos->y = (i * TILE_SIZE) - TILE_SIZE / 2;
	pos->dir = tab[i][j];
	return (pos);
}

t_player	*init_player(t_cub *cub)
{
	t_player	*player;

	player = malloc(sizeof(player));
	if (!player)
		return (NULL);
	player->pos = find_player(cub->char_map);
	if (player->pos->dir == 'N')
		player->rotation_angle = (PI) * 0.5;
	if (player->pos->dir == 'E')
		player->rotation_angle = 0;
	if (player->pos->dir == 'S')
		player->rotation_angle = (3 * PI) * 0.5;
	if (player->pos->dir == 'W')
		player->rotation_angle = PI;
	return (player);
}
