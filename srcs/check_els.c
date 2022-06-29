/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_els.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:04:17 by clmurphy          #+#    #+#             */
/*   Updated: 2022/06/28 14:16:19 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_borders(t_map **map)
{
	(void)map;
	printf("borders\n");
	return (0);
}

int	check_elems(t_map **map)
{
	t_map	*temp;
	int		i;
	int		ret;
	t_flags	flags;

	init_flags(&flags);
	i = 0;
	temp = *map;
	while (temp != NULL && all_flags(&flags) == 0)
	{
		while (temp->line[i] && all_flags(&flags) == 0)
		{
			ft_isspace(temp->line, &i);
			ret = verify_ele(temp->line, &i, &flags);
			if (ret > 0)
				temp->texture = ret;
			else
				return (-1);
		}
		temp = temp->next;
		i = 0;
	}
	return (0);
}

int	verify_ele(char *str, int *i, t_flags *flags)
{
	if (ft_strncmp(str + *i, "SO", 2) == 0 && flags->s == 0)
	{
		flags->s = 1;
		return (1);
	}
	if (ft_strncmp(str + *i, "NO", 2) == 0 && flags->n == 0)
	{
		flags->s = 1;
		return (1);
	}
	if (ft_strncmp(str + *i, "WE", 2) == 0 && flags->w == 0)
	{
		flags->s = 1;
		return (1);
	}
	if (ft_strncmp(str + *i, "EA", 2) == 0 && flags->e == 0)
	{
		flags->s = 1;
		return (1);
	}
	return (-1);
}

void	init_flags(t_flags *flags)
{
	flags->n = 0;
	flags->s = 0;
	flags->e = 0;
	flags->w = 0;
}

int	all_flags(t_flags *flags)
{
	int	ret;

	ret = 0;
	if (flags->n == 1)
		ret = 1;
	else
		return (0);
	if (flags->s == 1)
		ret = 1;
	else
		return (0);
	if (flags->e == 1)
		ret = 1;
	else
		return (0);
	if (flags->w == 1)
		ret = 1;
	else
		return (0);
	return (ret);
}
