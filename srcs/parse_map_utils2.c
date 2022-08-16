/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:34:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 09:45:08 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	configs_filled(t_cub *cub)
{
	if (cub->n_path && cub->s_path && cub->e_path && cub->w_path)
	{
		if (cub->f_color != 0 && cub->c_color != 0) //valgrind error uninitialised values
			return (1);
	}
	return (0);
}

int	check_line(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (str[0] != '1')
		return (-1);
	if (str[size - 1] != '1')
		return (-1);
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
