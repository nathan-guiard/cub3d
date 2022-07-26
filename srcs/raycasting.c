/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/26 14:46:27 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_cub *cub)
{
	t_player	*player;

	cub->fov_an = 60 * (PI / 180);
	cub->col_width = 4;
	cub->no_rays = WIDTH / cub->col_width;
	player = init_player(cub);
	DrawCircle(player->pos->x, player->pos->y, 2, cub);
	cast_all_rays(cub, player);
	return (0);
}

void	DrawCircle(int x, int y, int r, t_cub *cub)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	for(i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		my_pixel_put(&cub->mlx.img, x + x1, y + y1, 0x00FF0000);
	}
}

void	DrawCircle2(int x, int y, int r, t_cub *cub)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	for(i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		my_pixel_put(&cub->mlx.img, x + x1, y + y1, 0x800080);
	}
}

int	cast_all_rays(t_cub *cub, t_player *player)
{
	int		i;

	i = 0;
	cub->ray_angle = player->rotation_angle - (cub->fov_an / 2);
	printf("fov / 2 = %f\n", (cub->fov_an / 2));
	while (i < cub->no_rays)
	{
		init_ray(cub);
		cast_ray(&cub->ray, player, cub, i);
		cub->ray_angle += cub->fov_an / cub->no_rays;
		project_wall(cub, i);
		i++;
	}
	return (0);
}

int	project_wall(t_cub *cub, int col_id)
{
	float	proj_wall_height;
	float	wall_height;
	float	dist_pp;
	int		top_p;
	int		bottom_p;

	dist_pp = (WIDTH / 2) / tan(cub->fov_an / 2);
	proj_wall_height = (TILE_SIZE / cub->ray.distance) * dist_pp;
	wall_height = (int)proj_wall_height;
	top_p = (HEIGTH / 2) - (wall_height / 2);
	if (top_p < 0)
		top_p = 0;
	bottom_p = (HEIGTH / 2) + (wall_height / 2);
	if (bottom_p > HEIGTH)
		bottom_p = HEIGTH;
	cast_col(top_p, bottom_p, cub, col_id);
	return (0);
}

int	cast_col(int top_p, int bottom_p, t_cub *cub, int	col_id)
{
	int	save_b;
	int	x;
	int	i;

	save_b = bottom_p;
	x = col_id * cub->col_width;
	printf("x is %d save b = %d\n, top_p = %d\n\n", x, save_b, top_p);
	while (save_b >= top_p)
	{
		i = 0;
		while (i < cub->col_width)
		{
			my_pixel_put(&cub->mlx.img, x + i, save_b, 0x800080);
			i++;
		}
		save_b--;
	}
	return (0);
}

void	init_ray(t_cub *cub)
{
	cub->ray.hit_x = 0;
	cub->ray.hit_y = 0;
	cub->ray.xstep = 0;
	cub->ray.ystep = 0;
	cub->ray.yintercept = 0;
	cub->ray.xintercept = 0;
	cub->ray.up = 0;
	cub->ray.down = 0;
	cub->ray.left = 0;
	cub->ray.right = 0;
	cub->ray.wall_x = 0;
	cub->ray.wall_y = 0;
	cub->ray.distance = 2147483647;
}

int	cast_ray(t_ray *ray, t_player *player, t_cub *cub, int col_id)
{
	cub->ray_angle = normalize_angle(cub->ray_angle);
	ray_direction(ray, col_id, cub->ray_angle);
	horizontal_colis(&cub->ray, player, cub, cub->ray_angle);
	//if (cub->ray.wall_x == 1)
	//DrawCircle(ray->hit_x, ray->hit_y, 2, cub);
	vertical_colis(&cub->ray, player, cub, cub->ray_angle);
//	if (ray->wall_y == 1)
	//DrawCircle2(ray->hit_x, ray->hit_y, 2, cub);
	return (0);
}

int	vertical_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	ray->xintercept = floorf(player->pos->x / TILE_SIZE) * TILE_SIZE;
	if (ray->right == 1)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = (player->pos->y + (player->pos->x - ray->xintercept)) \
	* tan(ray_angle);
	ray->ystep = TILE_SIZE * tan(ray_angle);
	ray->xstep = TILE_SIZE;
	if (ray->left == 1)
		ray->xstep *= -1;
	if ((ray->up == 1 && ray->ystep > 0) || \
	(ray->down && ray->ystep < 0))
		ray->ystep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * TILE_SIZE) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * TILE_SIZE))
	{
		if (is_wall(cub->char_map, (ray->xintercept + ray->left), \
		ray->yintercept))
		{
			if (ray->distance > hypot((player->pos->x - ray->xintercept), \
			(player->pos->y - ray->yintercept)))
			{
				ray->distance = hypot((player->pos->x - ray->xintercept), \
			(player->pos->y - ray->yintercept));
				ray->wall_y = 1;
				ray->hit_x = ray->xintercept;
				ray->hit_y = ray->yintercept;
			}			
			break ;
		}
		else
		{
			ray->xintercept += ray->xstep;
			ray->yintercept += ray->ystep;
		}
	}
	return (0);
}

int	horizontal_colis(t_ray *ray, t_player *player, t_cub *cub, float ray_angle)
{
	ray->yintercept = floorf(player->pos->y / TILE_SIZE) * TILE_SIZE;
	if (ray->down == 1)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = player->pos->x + (player->pos->y - ray->yintercept) \
	/ tan(ray_angle);
	ray->ystep = TILE_SIZE;
	ray->xstep = TILE_SIZE / tan(ray_angle);
	if (ray->up == 1)
		ray->ystep *= -1;
	if ((ray->left == 1 && ray->xstep > 0) || \
	(ray->right && ray->xstep < 0))
		ray->xstep *= -1;
	while (ray->xintercept > 0 && ray->xintercept < (cub->width * TILE_SIZE) \
	&& ray->yintercept > 0 && ray->yintercept < (cub->height * TILE_SIZE))
	{
		if (is_wall(cub->char_map, ray->xintercept, \
		(ray->yintercept - ray->up)))
		{
			if (ray->distance > hypot((player->pos->x - ray->xintercept), \
			(player->pos->y - ray->yintercept)))
			{
				ray->distance = hypot((player->pos->x - ray->xintercept), \
			(player->pos->y - ray->yintercept));
				ray->wall_x = 1;		
			ray->hit_x = ray->xintercept;
			ray->hit_y = ray->yintercept;
			}
			break ;
		}
		else
		{
			ray->xintercept += ray->xstep;
			ray->yintercept += ray->ystep;
		}
	}
	return (0);	
}

	int is_wall(char **tab, int xinter, int yinter)
{
	int	i;
	int	j;

	j = floorf(xinter / TILE_SIZE);
	i = floorf(yinter / TILE_SIZE);
	if (tab[i + 1][j] == '1')
		return (1);
	else
		return (0);
}

int	ray_direction(t_ray *ray, int col_id, float ray_angle)
{
	(void)col_id;
	if (ray_angle > 0 && ray_angle < PI)
		ray->up = 1;
	else
		ray->down = 1;
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
		ray->right = 1;
	else
		ray->left = 1;
	return (0);
}

float	normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle > 2 * PI)
		ray_angle -= TWO_PI;
	if (ray_angle < 2 * -PI)
		ray_angle += TWO_PI;
	if (ray_angle < 0)
		ray_angle += TWO_PI;
	return (ray_angle);
}
