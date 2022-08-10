/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:06:13 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/10 11:17:34 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"   

int	project_wall(t_cub *cub, int col_id)
{
	float	proj_wall_height;
	float	dist_pp;
	float	ray_distance;
	int		top_p;
	int		bottom_p;

	ray_distance = cub->ray.distance * \
	cos(cub->player->rotation_angle - cub->ray_angle);
	dist_pp = (WIDTH / 2) / tan(cub->fov_an / 2);
	proj_wall_height = (TILE_SIZE / ray_distance) * dist_pp;
	cub->ray.w_height = (int)proj_wall_height;
	top_p = (HEIGTH / 2) - (cub->ray.w_height / 2);
	if (top_p < 0)
		top_p = 0;
	bottom_p = (HEIGTH / 2) + (cub->ray.w_height / 2);
	if (bottom_p > HEIGTH)
		bottom_p = HEIGTH;
	set_wall_id(cub);
	cast_col(top_p, bottom_p, cub, col_id);
	return (0);
}

void	set_wall_id(t_cub *cub)
{
	if (cub->ray.up == 1 && cub->ray.wall_x == 1)
		cub->ray.w_id = 0;
	if (cub->ray.down == 1 && cub->ray.wall_x == 1)
		cub->ray.w_id = 1;
	if (cub->ray.right == 1 && cub->ray.wall_y == 1)
		cub->ray.w_id = 2;
	else if (cub->ray.left == 1 && cub->ray.wall_y == 1)
		cub->ray.w_id = 3;
}

int	get_xoffset(t_cub *cub)
{
	int	offsetx;

	if (cub->ray.wall_y == 1)
		offsetx = ((int)cub->ray.hit_y * \
		cub->text[cub->ray.w_id].w / TILE_SIZE) % cub->text[cub->ray.w_id].w;
	else
		offsetx = ((int)cub->ray.hit_x * \
		cub->text[cub->ray.w_id].w / TILE_SIZE) % cub->text[cub->ray.w_id].w;
	return (offsetx);
}
