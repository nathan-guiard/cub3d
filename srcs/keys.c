/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:08:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/11 17:40:02 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hooks(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 17, 0, ft_close, &cub->mlx);
	mlx_hook(cub->mlx.win, 2, 1L << 0, check_key, &cub->mlx);
}

int	check_key(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		ft_close(cub);
	return (0);
}

int	ft_close(t_cub *cub)
{
    (void)cub;
	//free_cub(cub);
	//mlx_destroy_image(cub->mlx.init, cub->mlx.img.img);
	//mlx_destroy_window(cub->mlx.init, cub->mlx.win);
	//mlx_destroy_display(cub->mlx.init);
	//free(cub->mlx.init);
	exit(0);
	return (0);
}
