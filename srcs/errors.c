/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:27:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 13:20:32 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(t_cub *cub, t_map **map, char *str)
{
	printf("\033[1m\033[31m%s\n", str);
	free(cub);
	ft_my_lstclear(map);
	exit(127);
}

void	ft_error2(t_cub *cub, char *str)
{
	printf("\033[1m\033[31m%s\n", str);
	free(cub);
	exit(127);
}
