/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:31:35 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 15:13:57 by clmurphy         ###   ########.fr       */
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
		if (line[0] == '\n')
		{
			free(line);
			line = NULL;
			line = get_next_line(fd);
			continue ;
		}
		ft_my_lstadd_back(&map, ft_my_lstnew(line));
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	cub->map = map;
	if (check_chars(&map, cub) == -1)
		return (-1);
	print_map(cub);
	return (1);
}

int	create_map(t_map *map, t_cub *cub)
{
	char	**tab;
	int		i;
	int		size;

	i = 0;
	cub->height = ft_my_lstsize(map);
	cub->width = ft_lst_width(map);
	if (verify_borders(map, cub) == -1)
		ft_error(cub, &map, "ERROR : Check map borders");
	tab = malloc(sizeof(char *) * (cub->height + 1));
	if (!tab)
		ft_error(cub, &map, "ERROR : malloc error");
	while (map != NULL)
	{
		set_tab(tab, &i, cub, map);
		map = map->next;
	}
	tab[i] = '\0';
	cub->char_map = tab;
	return (1);
}

void	set_tab(char **tab, int *i, t_cub *cub, t_map *map)
{
	int	ret;

	ret = 0;
	if (i == 0 || i == cub->height)
			ret = check_first_and_last_line(map->line);
		ret = check_line(map->line, ret);
		if (ret == -1)
			ft_error(cub, &map, "ERROR : map error");
		size = ft_strlen(map->line);
		tab[i] = malloc(sizeof(char) * (size + 1));
		if (!tab[i])
			ft_error(cub, &map, "ERROR : malloc error");
		tab[i] = map->line;
		i++;
}
