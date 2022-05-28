/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:13:41 by nguiard           #+#    #+#             */
/*   Updated: 2021/11/26 11:45:20 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (c % 256))
			p = (char *)s + i;
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	return (p);
}
