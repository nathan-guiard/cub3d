/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_els.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:17 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/12 16:11:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verify_borders(t_map *map, t_cub *cub)
{
	int	i;
	int	j;
	int	closed;

	(void)map;
	i = 1;
	j = 0;
	ft_isspace(cub->char_map[i], &j);
	if (cub->char_map[i][j] != '1')
		return (-1);
	closed = 0;
	while (i <= cub->height)
	{
		j = 0;
		while (cub->char_map[i][j] != '\0' && cub->char_map[i][j] != 'v')
		{
			if (ft_isset(cub->char_map[i][j], "NSEW01 v") == -1)
				ft_error(cub, &cub->map, "invalid character in map");
			if (cub->char_map[i][j] == '1')
			{
				if (closed == 1 || closed == 2)
					closed = 2;
				else
					closed = 1;
			}
			else
			{
				if (closed == 2)
					closed = 1;
				if (i == 1)
					return (-1);
			}
			j++;
		}
		if (closed != 2)
			return (-1);
		i++;
		closed = 0;
	}
	i = 1;
	j = 0;
	while (j <= cub->width - 1)
	{
		i = 1;
		while (cub->char_map[i][j] && cub->char_map[i][j] != 'v')
		{
			if (ft_isset(cub->char_map[i][j], "NSEW01 v") == -1)
				ft_error(cub, &cub->map, "invalid character in map");
			if (cub->char_map[i][j] == '1')
			{
				if (closed == 1 || closed == 2)
					closed = 2;
				else
					closed = 1;
			}
			else
			{
				if (cub->char_map[i][j] == 32 && closed != 2)
					return (-1);
				else if (cub->char_map[i][j] == '0' && cub->char_map[i - 1][j] == 32)
					return (-1);
				else if (closed == 2 && cub->char_map[i][j] != 32)
					closed = 1;
			}
			i++;
		}
		if (closed != 2)
			return (-1);
		j++;
		closed = 0;
	}
	return (1);
}

int	compare_strings(char *s_long, char *s_short)
{
	int	i;

	i = 0;
	if (s_long[i] == '0')
		return (-1);
	while (s_short[i])
	{
		if (!s_short[i + 1] && s_long[i] != '1')
			return (-1);
		i++;
	}
	while (s_long[i])
	{
		if (s_long[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	check_chars(t_map **map, t_cub *cub)
{
	t_map	*temp;
	int		i;

	i = 0;
	temp = *map;
	while (temp != NULL && configs_filled(cub) != 1 && temp->line)
	{
		i = 0;
		ft_isspace(temp->line, &i);
		if (temp->line[i] == '1' || temp->line[i] == '0')
			ft_error(cub, &cub->map, "ERROR : Incomplte list of elements");
		check_pathnames(temp, cub, &i);
		temp = temp ->next;
	}
	create_map(temp, cub);
	return (1);
}

void	check_pathnames(t_map *temp, t_cub *cub, int *i)
{
	if (ft_strncmp(temp->line + *i, "NO", 2) == 0 || \
		ft_strncmp(temp->line + *i, "SO", 2) == 0 \
		|| ft_strncmp(temp->line + *i, "EA", 2) == 0 \
		|| ft_strncmp(temp->line + *i, "WE", 2) == 0)
	{
		if (set_path(temp->line, i, cub) == -1)
			ft_error(cub, &cub->map, "ERROR : texture path error");
	}
	if ((temp->line[*i] == 'F' && temp->line[*i + 1] == 32) || \
		(temp->line[*i] == 'C' && temp->line[*i + 1] == 32))
	{
		if (set_color(temp->line, cub, temp->line[*i]) == -1)
			ft_error(cub, &cub->map, "ERROR : color error");
	}
}
