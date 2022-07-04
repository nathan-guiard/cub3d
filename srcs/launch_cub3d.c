/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:04:05 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/04 17:24:22 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	launch_cub3d(t_cub *cub)
{
	print_map(cub);
	return (1);
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
