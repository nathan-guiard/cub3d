/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:31:36 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:52:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	is_valid(char c)
{
	if (c == 'd' || c == 'i')
		return (nombre);
	if (c == 'c')
		return (caractere);
	if (c == 'u')
		return (non_signe);
	if (c == 'p')
		return (pointeur);
	if (c == 'x')
		return (hex_min);
	if (c == 'X')
		return (hex_maj);
	if (c == '%')
		return (pourcent);
	if (c == 's')
		return (chaine);
	if (c == 'b')
		return (binaire);
	if (c == 'l')
		return (long_int);
	return (rien);
}

static t_type	*assign_tab(const char *s, int taille)
{
	t_type	*res;
	int		i;
	int		j;

	res = (t_type *)malloc(sizeof(t_type) * (taille + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '%' && (is_valid(s[i + 1]) != rien))
		{
			res[j] = is_valid(s[i + 1]);
			j++;
			i++;
		}
		i++;
	}
	res[j] = rien;
	return (res);
}

t_type	*printf_parsing(const char *s)
{
	int		i;
	int		taille;
	t_type	*res;

	i = 0;
	taille = 0;
	while (s[i])
	{
		if (s[i] == '%' && (is_valid(s[i + 1]) != rien))
			taille++;
		i++;
	}
	res = assign_tab(s, taille);
	return (res);
}
