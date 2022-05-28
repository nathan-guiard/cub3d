/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:48:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 13:08:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest[FD_MAX];
	char		*line;
	char		*to_free;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_MAX)
		return (NULL);
	rest[fd] = read_until_newline(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = the_line(rest[fd]);
	to_free = rest[fd];
	rest[fd] = new_rest(rest[fd]);
	if (to_free)
		free(to_free);
	to_free = NULL;
	return (line);
}

char	*the_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	return (get_line(s, i));
}

/* Donne la ligne que l'on veut dans rest[fd] */
char	*get_line(char *s, int i)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* Enleve la ligne dans rest */
char	*new_rest(char *rest)
{
	int		first_nl;
	int		after_nl;
	char	*new_rest;

	first_nl = 0;
	after_nl = 0;
	if (ft_strchr_g(rest, '\n') == 0)
		return (NULL);
	while (rest[first_nl] != '\n' && rest[first_nl] != '\0')
		first_nl++;
	while (rest[first_nl + after_nl] != '\0')
		after_nl++;
	new_rest = malloc(sizeof(char) * (after_nl + 1));
	if (!new_rest)
		return (NULL);
	after_nl = 0;
	first_nl++;
	while (rest[first_nl + after_nl] != '\0')
	{
		new_rest[after_nl] = rest[first_nl + after_nl];
		after_nl++;
	}
	new_rest[after_nl] = '\0';
	return (new_rest);
}

char	*read_until_newline(int fd, char *rest)
{
	int		lenread;
	char	*buff;

	lenread = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_strchr_g(rest, '\n') == 0 && lenread > 0)
	{
		lenread = read(fd, buff, BUFFER_SIZE);
		if (lenread <= 0)
			break ;
		buff[lenread] = '\0';
		rest = join_gnl(rest, buff);
		if (!rest)
			break ;
	}
	free(buff);
	return (rest);
}
