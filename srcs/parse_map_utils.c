/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:34:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/12 17:45:53 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		/* free(str);
		str = NULL; */
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
		/* free(str);
		str = NULL; */
		return (1);
	}
	if (str[j] == 'E')
	{
		if (cub->e_path)
			return (-1);
		cub->e_path = res;
		/* free(str);
		str = NULL; */
		return (1);
	}
	if (set_path3(str, res, cub, j) == 1)
		return (1);
	return (0);
}

int	set_path3(char *str, char *res, t_cub *cub, int j)
{
	if (str[j] == 'W')
	{
		if (cub->w_path)
			return (-1);
		cub->w_path = res;
		/* free(str);
		str = NULL; */
		return (1);
	}
	return (0);
}

int	get_text(t_cub *cub)
{
	cub->text[0].img = mlx_xpm_file_to_image(cub->mlx.init, cub->n_path, \
	&(cub->text[0].w), &(cub->text[0].h));
	if (!cub->text[0].img)
		return (-1);
	cub->text[1].img = mlx_xpm_file_to_image(cub->mlx.init, cub->s_path, \
	&(cub->text[1].w), &(cub->text[1].h));
	if (!cub->text[1].img)
		return (-1);
	cub->text[2].img = mlx_xpm_file_to_image(cub->mlx.init, cub->e_path, \
	&(cub->text[2].w), &(cub->text[2].h));
	if (!cub->text[2].img)
		return (-1);
	cub->text[3].img = mlx_xpm_file_to_image(cub->mlx.init, cub->w_path, \
	&(cub->text[3].w), &(cub->text[3].h));
	if (!cub->text[3].img)
		return (-1);
	get_text_addr(cub);
	return (0);
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
