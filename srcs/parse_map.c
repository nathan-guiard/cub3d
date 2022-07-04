/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:31:35 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 10:39:51 by clmurphy         ###   ########.fr       */
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
	return (1);
}

int	create_map(t_map *map, t_cub *cub)
{
	char	**tab;
	int		i;
	int		size;
	int		ret;

	i = 0;
	ret = 0;
	size = ft_my_lstsize(map);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		ft_error(cub, &map, "malloc error");
	while (map != NULL)
	{
		if (i == 0 || i == size)
			ret = check_first_and_last_line(map->line);
		ret = check_line(map->line);
		if (ret == -1)
			ft_error(cub, &map, "ERROR : map error");
		size = ft_strlen(map->line);
		tab[i] = malloc(sizeof(char) * (size + 1));
		if (!tab[i])
			ft_error(cub, &map, "malloc error");
		tab[i] = map->line;
		i++;
		map = map->next;
	}
	tab[i] = '\0';
	cub->char_map = tab;
	return (1);
}

int	check_chars(t_map **map, t_cub *cub)
{
	t_map	*temp;
	t_map	*temp2;
	int		i;

	i = 0;
	temp = *map;
	while (temp != NULL && configs_filled(cub) != 1 && temp->line)
	{
		i = 0;
		ft_isspace(temp->line, &i);
		if (temp->line[i] == '1' || temp->line[i] == 0)
			ft_error(cub, map, "Incomplte list of elements");
		if (ft_strncmp(temp->line + i, "NO", 2) == 0 || \
		ft_strncmp(temp->line + i, "SO", 2) == 0 \
		|| ft_strncmp(temp->line + i, "EA", 2) == 0 \
		|| ft_strncmp(temp->line + i, "WE", 2) == 0)
		{
			if (set_path(temp->line, &i, cub) == -1)
				ft_error(cub, map, "texture path error");
		}
		if ((temp->line[i] == 'F' && temp->line[i + 1] == 32) || \
		(temp->line[i] == 'C' && temp->line[i + 1] == 32))
		{
			if (set_color(temp->line, cub, temp->line[i]) == -1)
				ft_error(cub, map, "color error");
		}
		temp2 = temp;
		temp = temp ->next;
		free(temp2);
	}
	create_map(temp, cub);
	return (1);
}

int	set_color(char *str, t_cub *cub, char c)
{
	char			**tab;
	int				i;
	unsigned int	rgb;
	int				alpha;

	alpha = 255;
	rgb = (alpha << 24);
	i = 1;
	ft_isspace(str, &i);
	tab = ft_split(str + i, ',');
	if (!tab)
		return (-1);
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
			return (-1);
		i++;
	}
	rgb = rgb | (ft_atoi(tab[0]) << 16);
	rgb = rgb | (ft_atoi(tab[1]) << 8);
	rgb = rgb | (ft_atoi(tab[0]));
	if (c == 'F')
		cub->f_color = rgb;
	if (c == 'C')
		cub->c_color = rgb;
	return (1);
}
