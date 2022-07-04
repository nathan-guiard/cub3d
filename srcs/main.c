/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:16:48 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 09:35:50 by clmurphy         ###   ########.fr       */
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

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		return (NULL);
	cub->map = ft_my_lstnew(NULL);
	/* cub->n_path = NULL;
	cub->s_path = NULL;
	cub->e_path = NULL;
	cub->w_path = NULL; */
	cub->width = 0;
	cub->height = 0;
	return (cub);
}
