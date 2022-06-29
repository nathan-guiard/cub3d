/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:16:48 by clmurphy          #+#    #+#             */
/*   Updated: 2022/06/28 14:07:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int	ret;

	ret = check_arguments(ac, av);
	if (ret == -1)
		return (-1);
	parse_map(ret);
	return (0);
}

int	parse_map(int fd)
{
	t_cub	*cub;
	char	*line;

	cub = NULL;
	ft_bzero(cub, sizeof(cub));
	cub->map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_my_lstadd_back(&cub->map, ft_my_lstnew(line));
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (check_chars(&cub->map) == -1)
		return (-1);
	if (check_borders(&cub->map) == -1)
		return (-1);
	if (check_elems(&cub->map) == -1)
		return (-1);
	return (1);
}

int	check_chars(t_map **map)
{
	t_map	*temp;
	int		i;

	i = 0;
	temp = *map;
	while (temp != NULL)
	{
		while (temp->line[i])
		{
			if (ft_isset(temp->line[i], "01NSEW") == -1)
				return (-1);
			i++;
		}
		temp = temp ->next;
	}
	return (1);
}
