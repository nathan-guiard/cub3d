/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:48:30 by clmurphy          #+#    #+#             */
/*   Updated: 2022/09/06 11:40:10 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**create_map2(t_cub *cub, int *i, int *j)
{
	char	**tab;

	*i = 0;
	*j = 0;
	if (cub->height < 3)
		ft_error(cub, &cub->map, "ERROR : map too short");
	tab = ft_calloc(sizeof(char *), (cub->height + 3));
	if (!tab)
		ft_error(cub, &cub->map, "ERROR : malloc error");
	tab[*i] = ft_calloc(sizeof(char), cub->width + 2);
	if (!tab[*i])
	{
		free_tabtab(tab);
		ft_error(cub, &cub->map, "ERROR : malloc error");
	}
	while ((*j) < cub->width)
	{
		tab[*i][*j] = 'v';
		(*j)++;
	}
	tab[*i][*j] = '\0';
	return (tab);
}

void	crete_map_tab_error(char **tab, t_cub *cub)
{
	free_tabtab(tab);
	ft_error(cub, &cub->map, "ERROR : malloc error");
}

void	create_map3(t_cub *cub, char **tab, int *i, int *j)
{
	while ((*j) < cub->width)
	{
		tab[*i][*j] = 'v';
		(*j)++;
	}
	tab[*i][*j] = '\0';
	(*i)++;
	cub->char_map[*i] = '\0';
	if (verify_borders(cub->char_map, cub) == -1)
		ft_error(cub, &cub->map, "ERROR : Check map borders");
}

void	check_map_tab(t_cub *cub, t_map *map, int *k, int *i)
{
	if (!map)
		ft_error(cub, &cub->map, "ERROR : map error");
	cub->char_map[*i] = malloc(sizeof(char) * (cub->width) + 2);
	if (!cub->char_map[*i])
	{
		cub->char_map[*i] = NULL;
		ft_error(cub, &cub->map, "ERROR : malloc error");
	}
	*k = 0;
}

void	set_tab2(t_cub *cub, t_map *map, int *i, int *k)
{
	if (check_line(map->line) == -1)
	{
		cub->char_map[*i + 1] = NULL;
		ft_error(cub, &cub->map, "ERROR : map border error");
	}
	free(map->line);
	map->line = NULL;
	cub->char_map[*i][*k] = 'v';
	(*k)++;
}
