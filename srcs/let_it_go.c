/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_it_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:12:54 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 10:43:27 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	free_tab(cub->char_map);
	cub->char_map = NULL;
	if (cub->n_path)
		free(cub->n_path);
	if (cub->s_path)
		free(cub->s_path);
	if (cub->e_path)
		free(cub->e_path);
	if (cub->w_path)
		free(cub->w_path);
	ft_my_lstclear(&cub->map);
	if (cub->player)
		free(cub->player);
	free(cub);
}

void	end_cub(t_cub *cub, t_map **map)
{
	t_map	*temp;

	temp = *map;
	while ((temp)->next != NULL)
	{
		free((temp)->line);
		temp = (temp)->next;
	}
	free((temp)->line);
	ft_my_lstclear(&cub->map);
	free_cub(cub);
}
