/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_whole_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:17:12 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 13:10:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_whole_file(int fd)
{
	char	*buff;
	char	*res;
	char	*to_free;
	int		line;

	line = 0;
	to_free = NULL;
	to_free++;
	buff = NULL;
	res = NULL;
	while (buff || line == 0)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		line++;
		to_free = res;
		res = join(res, buff);
	}
	return (res);
}
