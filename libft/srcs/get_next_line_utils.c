/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:29:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 13:08:14 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_g(const char *s, int c)
{
	int		i;
	char	*p;

	if (!s)
		return (0);
	p = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (c % 256))
			return (p);
		i++;
		p++;
	}
	if (s[i] == '\0' && c == '\0')
		return (p);
	return (NULL);
}

char	*join_gnl(char *rest, char *buff)
{
	char	*new_rest;

	if (!rest)
	{
		rest = malloc(sizeof(char));
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	if (!buff)
	{
		buff = malloc(sizeof(char));
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	new_rest = ft_strjoin(rest, buff);
	free(rest);
	rest = NULL;
	return (new_rest);
}
