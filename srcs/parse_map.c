/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:31:35 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/09 15:14:38 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(int fd)
{
	t_cub	*cub;
	t_map	*map;
	char	*line;

	cub = init_cub();
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

	j = 0;
	temp = map;
	i = 0;
	cub->height = ft_my_lstsize(map);
	cub->width = ft_lst_width(map);
	if (cub->height < 3)
		ft_error(cub, &cub->map, "ERROR : map too short");
	tab = malloc(sizeof(char *) * (cub->height + 3));
	if (!tab)
		ft_error(cub, &cub->map, "ERROR : malloc error");
	tab[i] = malloc(sizeof(char) * cub->width + 2);
	if (!tab)
		ft_error(cub, &cub->map, "ERROR : malloc error");
	while (j < cub->width)
	{
		tab[i][j] = 'v';
		j++;
	}
	tab[i][j] = '\0';
	i++;
	cub->char_map = tab;
	while (temp != NULL)
	{
		set_tab(cub->char_map, &i, cub, temp);
		i++;
		temp = temp->next;
	}
	j = 0;
	tab[i] = malloc(sizeof(char) * cub->width + 1);
	if (!tab)
		ft_error(cub, &cub->map, "ERROR : malloc error");
	while (j < cub->width)
	{
		tab[i][j] = 'v';
		j++;
	}
	tab[i][j] = '\0';
	i++;
	cub->char_map[i] = '\0';
	if (verify_borders(cub->char_map, cub) == -1)
		ft_error(cub, &cub->map, "ERROR : Check map borders");
	return (1);
}

void	set_tab(char **tab, int *i, t_cub *cub, t_map *map)
{
	int	k;

	if (!map)
		ft_error(cub, &cub->map, "ERROR : map error");
	tab[*i] = malloc(sizeof(char) * (cub->width) + 2);
	if (!tab[*i])
	{
		tab[*i] = NULL;
		ft_error(cub, &cub->map, "ERROR : malloc error");
	}
	k = 0;
	while (k < cub->width)
	{
		if (k < map->len)
		{
			while (map->line[k])
			{
				if (map->line[k] == 32)
					map->line[k] = '1';
				tab[*i][k] = map->line[k];
				k++;
			}
		}
		if (check_line(map->line) == -1)
		{
			tab[*i + 1] = NULL;
			ft_error(cub, &cub->map, "ERROR : map border error");
		}
		tab[*i][k] = 'v';
		k++;
	}
	tab[*i][k] = '\0';
}
