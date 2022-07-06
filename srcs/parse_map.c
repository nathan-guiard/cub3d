/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:31:35 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/06 10:28:46 by clmurphy         ###   ########.fr       */
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
	t_map	*temp;

	temp = map;
	i = 0;
	cub->height = ft_my_lstsize(map);
	cub->width = ft_lst_width(map);
	if (verify_borders(map, cub) == -1)
		ft_error(cub, &cub->map, "ERROR : Check map borders");
	tab = malloc(sizeof(char *) * (cub->height + 1));
	if (!tab)
		ft_error(cub, &cub->map, "ERROR : malloc error");
	cub->char_map = tab;
	while (temp != NULL)
	{
		set_tab(cub->char_map, &i, cub, temp);
		temp = temp->next;
	}
	cub->char_map[i] = '\0';
	return (1);
}

void	set_tab(char **tab, int *i, t_cub *cub, t_map *map)
{
	int	ret;

	ret = 0;
	if (*i == 0 || *i == cub->height)
		ret = check_first_and_last_line(map->line);
	ret = check_line(map->line, ret);
	if (ret == -1)
	{
		tab[*i] = NULL;
		ft_error(cub, &cub->map, "ERROR : map error");
	}	
	tab[*i] = ft_strdup(map->line);
	(*i)++;
}
