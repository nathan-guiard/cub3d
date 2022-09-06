/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:31:35 by clmurphy          #+#    #+#             */
/*   Updated: 2022/09/06 11:40:18 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(int fd)
{
	t_cub	*cub;
	t_map	*map;
	char	*line;

	cub = init_cub();
	if (!cub)
		exit(1);
	cub->fd = fd;
	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		create_list(line, &map);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	cub->map = map;
	if (check_chars(&cub->map, cub) == -1)
		return (-1);
	launch_cub3d(cub);
	end_cub(cub, &cub->map);
	return (1);
}

int	create_list( char *line, t_map **map)
{
	if (line[0] == '\n')
	{
		free(line);
		line = NULL;
		return (-1);
	}
	ft_my_lstadd_back(map, ft_my_lstnew(line));
	free(line);
	line = NULL;
	return (1);
}

int	create_map(t_map *map, t_cub *cub)
{
	char	**tab;
	int		i;
	int		j;
	t_map	*temp;

	temp = map;
	cub->height = ft_my_lstsize(map);
	cub->width = ft_lst_width(map);
	tab = create_map2(cub, &i, &j);
	i++;
	cub->char_map = tab;
	while (temp != NULL)
	{
		set_tab(cub->char_map, &i, cub, temp);
		i++;
		temp = temp->next;
	}
	j = 0;
	tab[i] = ft_calloc(sizeof(char), cub->width + 1);
	if (!tab[i])
		crete_map_tab_error(tab, cub);
	create_map3(cub, tab, &i, &j);
	return (1);
}

void	set_tab(char **tab, int *i, t_cub *cub, t_map *map)
{
	int	k;

	check_map_tab(cub, map, &k, i);
	while (k < cub->width)
	{
		if (k < map->len)
		{
			while (map->line[k])
			{
				if (ft_isset(map->line[k], "10 NSEW\0") == -1)
				{
					tab[*i + 1] = NULL;
					ft_error(cub, &cub->map, "ERROR : invalid character");
				}
				if (map->line[k] == 32)
					map->line[k] = '1';
				tab[*i][k] = map->line[k];
				k++;
			}
		}
		set_tab2(cub, map, i, &k);
	}
	tab[*i][k] = '\0';
}
