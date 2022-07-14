/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:27:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/07/14 16:43:36 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(t_cub *cub, t_map **map, char *str)
{
	t_map	*temp;

	temp = *map;
	ft_putstr_fd("\033[31;1m", 1);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[m", 1);
	while ((temp)->next != NULL)
	{
		free((temp)->line);
		temp = (temp)->next;
	}
	free((temp)->line);
	ft_my_lstclear(&cub->map);
	free_cub(cub);
	exit(127);
}

void	ft_error2(t_cub *cub, t_map **map, char *res, char *str)
{
	t_map	*temp;

	temp = *map;
	ft_putstr_fd("\033[31;1m", 1);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[m", 1);
	free(res);
	while (temp->next != NULL)
	{
		free(temp->line);
		temp = temp->next;
	}
	free(temp->line);
	ft_my_lstclear(&cub->map);
	free_cub(cub);
	exit(127);
}

void	ft_error_cub(t_cub *cub, t_map **map, char *str)
{
	t_map	*temp;

	temp = *map;
	ft_putstr_fd("\033[31;1m", 1);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[m", 1);
	while ((temp)->next != NULL)
	{
		free((temp)->line);
		temp = (temp)->next;
	}
	free((temp)->line);
	ft_my_lstclear(&cub->map);
	//free(cub->mlx);
	free_cub(cub);
	exit(127);
}

void	ft_ray_error(t_cub *cub, t_ray *ray, t_player *player, char *str)
{
	t_map	*temp;
	//int		i;

	//i = 0;
	temp = (cub->map);
	ft_putstr_fd("\033[31;1m", 1);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[m", 1);
	while (temp->next != NULL)
	{
		free(temp->line);
		temp = temp->next;
	}
	free(temp->line);
	ft_my_lstclear(&cub->map);
	free_cub(cub);
	//while (i < WIDTH)
		free(ray);
	free(player);
}
