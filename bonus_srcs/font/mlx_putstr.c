/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:26:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static char	real_toupper(unsigned int i, char c)
{
	(void)i;
	return(ft_toupper(c));
}

typedef	void	(*t_fnc)(t_img*, t_co, int);
void			init_fnc_tab(t_fnc tab[38]);

void	mlx_putstr(t_img *img, char *str, t_co co, int size)
{
	t_fnc	tab[38];
	int		i;

	if (!str)
		return ;
	i = 0;
	str = ft_strmapi(str, real_toupper);
	init_fnc_tab(tab);
	while (str[i])
	{
		if (ft_isalpha(str[i]) || ft_isdigit(str[i]) ||
			str[i] == '/' || str[i] == ' ' || str[i] == '.')
		{
			if (ft_isalpha(str[i]))
				tab[str[i] - 'A'](img, co, size);
			if (ft_isdigit(str[i]))
				tab[str[i] - '0' + 26](img, co, size);
			if (str[i] == '/')
				tab[37](img, co, size);
			if (str[i] == '.')
				tab[36](img, co, size);
			co.x += size * 10;
		}
		i++;
	}
	free(str);
}

static void	init_fnc_tab2(t_fnc tab[38]);

void	init_fnc_tab(t_fnc tab[38])
{
	tab[0] = ft_a;
	tab[1] = ft_b;
	tab[2] = ft_c;
	tab[3] = ft_d;
	tab[4] = ft_e;
	tab[5] = ft_f;
	tab[6] = ft_g;
	tab[7] = ft_h;
	tab[8] = ft_i;
	tab[9] = ft_j;
	tab[10] = ft_k;
	tab[11] = ft_l;
	tab[12] = ft_m;
	tab[13] = ft_n;
	tab[14] = ft_o;
	tab[15] = ft_p;
	tab[16] = ft_q;
	tab[17] = ft_r;
	tab[18] = ft_s;
	tab[19] = ft_t;
	tab[20] = ft_u;
	tab[21] = ft_v;
	tab[22] = ft_w;
	init_fnc_tab2(tab);
}

static void	init_fnc_tab2(t_fnc tab[38])
{
	tab[23] = ft_x;
	tab[24] = ft_y;
	tab[25] = ft_z;
	tab[26] = ft_0;
	tab[27] = ft_1;
	tab[28] = ft_2;
	tab[29] = ft_3;
	tab[30] = ft_4;
	tab[31] = ft_5;
	tab[32] = ft_6;
	tab[33] = ft_7;
	tab[34] = ft_8;
	tab[35] = ft_9;
	tab[36] = ft_dot;
	tab[37] = ft_slash;
}