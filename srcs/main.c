/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clodaghmurphy <clodaghmurphy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:16:48 by clmurphy          #+#    #+#             */
/*   Updated: 2022/06/29 18:05:25 by clodaghmurp      ###   ########.fr       */
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
	int		i; 

	cub = NULL;
	cub = init_cub();
	cub->map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] = '\n')
			continue;
		ft_my_lstadd_back(&cub->map, ft_my_lstnew(line));
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (check_chars(&cub->map) == -1)
		return (-1);
	/*if (check_borders(&cub->map) == -1)
		return (-1);
	if (check_elems(&cub->map) == -1)
		return (-1);*/
	return (1);
}

int	check_chars(t_map **map, t_cub *cub)
{
	t_map	*temp;
	int		i;

	i = 0;
	temp = *map;
	while (temp != NULL && configs_filled(cub) != 1)
	{
		i = 0;
		ft_isspace(temp->line, &i);
		if (ft_strncmp(temp->line + i, "N0", 2) == 0 || ft_strncmp(temp->line + i, "SO", 2) == 0 ||
			 ft_strncmp(temp->line + i, "EA", 2) == 0
			|| ft_strncmp(temp->line + i, "WE", 2) == 0 )
			{
				if (set_path(temp->line, &i, cub) == -1)
					return (-1);
				return (0);
			}
			if ((str[i] == 'F' && str[i + 1] == 32) || (str[i] == 'C' && str[i + 1] == 32))
			{
				set_color(temp->line, cub);
				return (0);
			}
		temp = temp ->next;
	}
	return (1);
}

int	set_path(char *str, int *i, t_cub *cub)
{
	int	j;
	char	*res;

	j = *i;
	*i += 2;
	ft_isspace(str, i);
	res = t_strdup(str + *i);
	if (!res)
		return (-1);
	if (str[j] == 'N')
		cub->n_path = res;
	if (str[j] == 'S')
		cub->n_path = res;
	if (str[j] == 'E')
		cub->n_path = res;
	if (str[j] == 'W')
		cub->n_path = res;
	return (0);
}

int	configs_filled(t_cub *cub)
{
	if (cub->n_path && cub->s_path && cub->e_path && cub->w_path)
	{
		if (cub->f_color != 0 && cub->c_color != 0)
			return (1);
	}
	return (0);
}

t_cub	*init_cub(void)
{
	t_cub	*cub;
	
	cub = malloc(sizeof(cub));
	if (!cub)
		return (NULL);
	cub->map = NULL;
	cub->n_path = NULL;
	cub->s_path = NULL;
	cub->e_path = NULL;
	cub->w_path = NULL;
	cub->width = 0;
	cub->height = 0;
	return (cub);
}
