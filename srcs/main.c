/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:16:48 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 10:55:54 by nguiard          ###   ########.fr       */
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
	return (cub);
}
