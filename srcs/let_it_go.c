/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_it_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:12:54 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 18:04:22 by clmurphy         ###   ########.fr       */
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
	free_tab(cub->char_map);
	cub->char_map = NULL;
	ft_my_lstclear(&cub->map);
}
