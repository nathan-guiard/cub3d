/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:34:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 14:18:16 by clmurphy         ###   ########.fr       */
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

int	check_line(char *str, int ret)
{
	int	i;
	int	size;

	if (ret == -1)
		return (-1);
	size = ft_strlen(str);
	if (str[size - 1] == '\n')
		size = size - 1;
	i = 0;
	if (!str)
		return (-1);
	ft_isspace(str, &i);
	if (str[i] == '0' || str[size - 1] == '0')
		return (-1);
	while (i < size)
	{
		if (ft_isset(str[i], "01NSEW") == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_first_and_last_line(char *str)
{
	int	i;

	i = 0;
	ft_isspace(str, &i);
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
	{
		if (cub->n_path)
			ft_error2(cub, "ERROR : duplicte path names");
		cub->n_path = res;
	}
	if (str[j] == 'S')
	{
		if (cub->s_path)
			ft_error2(cub, "ERROR : duplicte path names");
		cub->s_path = res;
	}
	if (str[j] == 'E')
	{
		if (cub->e_path)
			ft_error2(cub, "ERROR : duplicte path names");
		cub->e_path = res;
	}
	if (str[j] == 'W')
	{
		if (cub->w_path)
			ft_error2(cub, "ERROR : duplicte path names");
		cub->w_path = res;
	}
	return (0);
}

void	print_map(t_cub *cub)
{
	int	i;

	i = 0;
	printf("\n\033[1m\033[35m		PATHS			\033[0m\n");
	printf("NORTH : %s\n", cub->n_path);
	printf("SOUTH : %s\n", cub->s_path);
	printf("EAST : %s\n", cub->e_path);
	printf("WEST : %s\n", cub->w_path);
	printf("\n\033[1m\033[35m		COLORS			\033[0m\n");
	printf("F is %x\n", cub->f_color);
	printf("C is %x\n", cub->c_color);
	printf("\n\033[1m\033[35m		MAP			\033[0m\n");
	while (cub->char_map[i])
	{
		printf("%s\n", cub->char_map[i]);
		i++;
	}
	printf("\n\033[1m\033[35m		MAP DATA		\033[0m\n");
	printf("HEIGHT : %d\n", cub->height);
	printf("WIDTH : %d\n", cub->width);
}
