/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 12:11:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_cub *cub)
{
	cub->fov_an = 60 * (PI / 180);
	cub->col_width = 1;
	cub->player = init_player(cub);
	if (!cub->player)
		ft_close(cub);
	cast_all_rays(cub, cub->player);
	return (0);
}

int	cast_all_rays(t_cub *cub, t_player *player)
{
	int		i;

	i = 0;
	cub->ray_angle = player->rotation_angle - (cub->fov_an / 2);
	while (i < WIDTH)
	{
		init_ray(cub);
		cast_ray(&cub->ray, player, cub, i);
		project_wall(cub, i);
		cub->ray_angle += cub->fov_an / WIDTH;
		i++;
	}
	return (0);
}

int	cast_ray(t_ray *ray, t_player *player, t_cub *cub, int col_id)
{
	(void)player;
	cub->ray_angle = normalize_angle(cub->ray_angle);
	ray_direction(ray, col_id, cub->ray_angle);
	horizontal_colis(&cub->ray, cub->player, cub, cub->ray_angle);
	vertical_colis(&cub->ray, cub->player, cub, cub->ray_angle);
	return (0);
}
