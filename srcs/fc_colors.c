/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:51:45 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 13:17:36 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_color(char *str, t_cub *cub, char c)
{
	char			**tab;
	int				i;
	unsigned int	rgb;
	int				alpha;

	alpha = 255;
	rgb = (alpha << 24);
	i = 1;
	ft_isspace(str, &i);
	tab = ft_split(str + i, ',');
	if (!tab || tablen(tab) != 3)
		return (free_tab(tab), -1);
	i = 0;
	while (i < 3)
	{
		if (my_atoi(tab[i]) > 255 || my_atoi(tab[i]) < 0)
		{
			free_tab(tab);
			return (-1);
		}
		i++;
	}
	assign_rgb(tab, &rgb, cub, c);
	free_tab(tab);
	return (1);
}

void	assign_rgb(char **tab, unsigned int *rgb, t_cub *cub, char c)
{
	*rgb = *rgb | (ft_atoi(tab[0]) << 16);
	*rgb = *rgb | (ft_atoi(tab[1]) << 8);
	*rgb = *rgb | (ft_atoi(tab[2]));
	if (c == 'F')
		cub->c_color = *rgb;
	if (c == 'C')
		cub->f_color = *rgb;
}

int	tablen(char	**tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);
}
