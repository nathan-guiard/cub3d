/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:34:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/27 17:14:55 by clmurphy         ###   ########.fr       */
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
	//t_img	textures[4];

	j = *i;
	*i += 2;
	ft_isspace(str, i);
	res = ft_strdup(str + *i);
	if (!res)
		return (-1);
	if (str[j] == 'N')
	{
		if (cub->n_path)
			ft_error2(cub, &cub->map, res, "ERROR : duplicte path names");
		cub->n_path = res;
		//textures[0] = get_text(cub, 0);
		return (1);
	}
	if (set_path2(str, res, cub, j) == -1)
		ft_error2(cub, &cub->map, res, "ERROR : duplicte path names");
	return (0);
}

int	set_path2(char *str, char *res, t_cub *cub, int j)
{
	if (str[j] == 'S')
	{
		if (cub->s_path)
			return (-1);
		cub->s_path = res;
		return (1);
	}
	if (str[j] == 'E')
	{
		if (cub->e_path)
			return (-1);
		cub->e_path = res;
		return (1);
	}
	if (str[j] == 'W')
	{
		if (cub->w_path)
			return (-1);
		cub->w_path = res;
		return (1);
	}
	return (0);
}
