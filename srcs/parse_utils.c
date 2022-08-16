/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:16:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/08/16 10:56:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

int	ft_isspace(char *str, int *i)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	return (0);
}

char	*my_strdup(const char *s)
{
	int		i;
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s) + 1;
	res = (char *)ft_calloc(size, sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
		if (s[i] == '\n')
			break ;
	}
	res[i] = '\0';
	return (res);
}

int	my_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;

	res = 0;
	s = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = (nptr[i] - 48) + res * 10;
		i++;
	}
	if (nptr[i] != '\0' || (nptr[i] < 48 && nptr[i] > 57))
		return (-1);
	return (res * s);
}
