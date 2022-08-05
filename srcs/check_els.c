/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_els.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:17 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/05 13:35:13 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verify_borders(char **tab, t_cub *cub)
{
	int	i;
	int	j;
	int	open;

	(void)cub;
	open = 0;
	j = 0;
	i = 1;
	while (tab[i][j])
	{
		i = 1;
		while (tab[i])
		{
			if (tab[i][j] == 'v')
				break ;
			if (tab[i][j] == '1')
				open = 1;
			else
				open = 0;
			i++;
		}
		if (open == 0)
			return (-1);
		j++;
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
