/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:27:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/05 13:59:44 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(t_cub *cub, t_map **map, char *str)
{
	(void)map;
	printf("\033[1m\033[31m%s\n", str);
	while ((*map)->next != NULL)
	{
		free((*map)->line);
		*map = (*map)->next;
	}
	free((*map)->line);
	ft_my_lstclear(&cub->map);
	free_cub(cub);
	exit(127);
}

void	ft_error2(t_cub *cub, t_map **map, char *res, char *str)
{
	(void)map;
	printf("\033[1m\033[31m%s\n", str);
	free(res);
	while ((*map)->next != NULL)
	{
		free((*map)->line);
		*map = (*map)->next;
	}
	free((*map)->line);
	free_cub(cub);
	exit(127);
}
