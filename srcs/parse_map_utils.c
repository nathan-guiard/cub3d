/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:34:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 10:45:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	configs_filled(t_cub *cub)
{
	if (cub->n_path && cub->s_path && cub->e_path && cub->w_path)
	{
		if (cub->f_color != 0 && cub->c_color != 0)
			return (1);
	}
	return (0);
}

int	check_line(char *str)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	if (str[size - 1] == '\n')
		size = size - 1;
	i = 0;
	if (!str)
		return (-1);
	while (i < size)
	{
		if (ft_isset(str[i], "01 NSEW") == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_first_and_last_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (-1);
		i++;
	}
	return (1);
}

int	set_path(char *str, int *i, t_cub *cub)
{
	int		j;
	char	*res;

	j = *i;
	*i += 2;
	ft_isspace(str, i);
	res = ft_strdup(str + *i);
	if (!res)
		return (-1);
	if (str[j] == 'N')
		cub->n_path = res;
	if (str[j] == 'S')
		cub->s_path = res;
	if (str[j] == 'E')
		cub->e_path = res;
	if (str[j] == 'W')
		cub->w_path = res;
	return (0);
}

void	print_map(t_cub *cub)
{
	int	i;

	i = 0;
	printf("		PATHS			\n");
	printf("NORTH : %s\n: ", cub->n_path);
	printf("SOUTH : %s\n: ", cub->s_path);
	printf("EAST : %s\n: ", cub->e_path);
	printf("WEST : %s\n: ", cub->w_path);
	printf("		COLORS			\n");
	printf("F is %d\n", cub->f_color);
	printf("C is %d\n", cub->c_color);
	printf("		MAP			\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
