/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_els.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:17 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 17:30:08 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verify_borders(t_map *map, t_cub *cub)
{
	t_map	*temp;
	int		ret;

	(void)cub;
	temp = map;
	ret = 1;
	while (temp->next != NULL && ret != -1)
	{
		if (temp->next->len > temp->len && ret != -1)
			ret = compare_strings(temp->next->line, temp->line);
		else if (temp->next->len < temp->len && ret != -1)
			ret = compare_strings(temp->line, temp->next->line);
		temp = temp->next;
	}
	return (ret);
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
		if (temp->line[i] == '1' || temp->line[i] == 0)
			ft_error(cub, map, "ERROR : Incomplte list of elements");
		check_pathnames(temp, map, cub, &i);
		temp = temp ->next;
	}
	create_map(temp, cub);
	return (1);
}

void	check_pathnames(t_map *temp, t_map **map, t_cub *cub, int *i)
{
	if (ft_strncmp(temp->line + *i, "NO", 2) == 0 || \
		ft_strncmp(temp->line + *i, "SO", 2) == 0 \
		|| ft_strncmp(temp->line + *i, "EA", 2) == 0 \
		|| ft_strncmp(temp->line + *i, "WE", 2) == 0)
	{
		if (set_path(temp->line, i, cub) == -1)
			ft_error(cub, map, "ERROR : texture path error");
	}
	if ((temp->line[*i] == 'F' && temp->line[*i + 1] == 32) || \
		(temp->line[*i] == 'C' && temp->line[*i + 1] == 32))
	{
		if (set_color(temp->line, cub, temp->line[*i]) == -1)
			ft_error(cub, map, "ERROR : color error");
	}
}
