/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:34:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/05 14:19:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	configs_filled(t_cub *cub)
{
	if (cub->n_path && cub->s_path && cub->e_path && cub->w_path)
	{
		if (cub->f_color != 0 && cub->c_color != 0)
			return (1);
	}
	return (0);
}

int	check_line(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (str[0] != '1')
		return (-1);
	if (str[size - 1] != '1')
		return (-1);
	return (1);
}

int	check_first_and_last_line(char *str)
{
	int	i;

	i = 0;
	ft_isspace(str, &i);
	while (str[i])
	{
		if (str[i] == '0')
			return (-1);
		i++;
	}
	return (1);
}

int	set_path(char *str, int *i, t_cub *cub)
{
	int		j;
	char	*res;
	int		len;

	j = *i;
	*i += 2;
	ft_isspace(str, i);
	res = ft_strdup(str + *i);
	if (!res)
		return (-1);
	if (str[j] == 'N')
	{
		if (cub->n_path)
			ft_error2(cub, &cub->map, res, "ERROR : duplicte path names");
		len = ft_strlen(res);
		if (res[len - 1] != 'x' && res[len -2] != 'p' && res[len -3])
			ft_error2(cub, &cub->map, res, "ERROR : invalid xpm");
		cub->n_path = res;
		return (1);
	}
	if (set_path2(str, res, cub, j) == -1)
		ft_error2(cub, &cub->map, res, "ERROR : duplicte path names");
	return (0);
}

int	set_path2(char *str, char *res, t_cub *cub, int j)
{
	if (str[j] == 'S')
	{
		if (cub->s_path)
			return (-1);
		cub->s_path = res;
		return (1);
	}
	if (str[j] == 'E')
	{
		if (cub->e_path)
			return (-1);
		cub->e_path = res;
		return (1);
	}
	if (str[j] == 'W')
	{
		if (cub->w_path)
			return (-1);
		cub->w_path = res;
		return (1);
	}
	return (0);
}

void	get_text(t_cub *cub)
{
	cub->text[0].img = mlx_xpm_file_to_image(cub->mlx.init, cub->n_path, \
	&(cub->text[0].w), &(cub->text[0].h));
	cub->text[1].img = mlx_xpm_file_to_image(cub->mlx.init, cub->e_path, \
	&(cub->text[1].w), &(cub->text[1].h));
	cub->text[2].img = mlx_xpm_file_to_image(cub->mlx.init, cub->s_path, \
	&(cub->text[2].w), &(cub->text[2].h));
	cub->text[3].img = mlx_xpm_file_to_image(cub->mlx.init, cub->w_path, \
	&(cub->text[3].w), &(cub->text[3].h));
}

void	get_text_addr(t_cub *cub)
{
	cub->text[0].addr = mlx_get_data_addr(cub->text[0].img, \
	&(cub->text[0].bpp), &(cub->text[0].len), &(cub->text[0].endian));
	cub->text[1].addr = mlx_get_data_addr(cub->text[1].img, \
	&(cub->text[1].bpp), &(cub->text[1].len), &(cub->text[1].endian));
	cub->text[2].addr = mlx_get_data_addr(cub->text[2].img, \
	&(cub->text[2].bpp), &(cub->text[2].len), &(cub->text[2].endian));
	cub->text[3].addr = mlx_get_data_addr(cub->text[3].img, \
	&(cub->text[3].bpp), &(cub->text[3].len), &(cub->text[3].endian));
}
