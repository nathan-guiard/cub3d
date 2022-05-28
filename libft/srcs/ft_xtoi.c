/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:19:32 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/29 11:26:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xtoi(char *s)
{
	unsigned int	i;
	int				res;
	char			c;

	res = 0;
	i = 0;
	if (!s)
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '0' && s[i + 1] == 'x')
		i += 2;
	while (s[i])
	{
		c = ft_toupper(s[i]);
		if ((c < '0') || (c > 'F') || ((c > '9') && (c < 'A')))
			break ;
		c -= '0';
		if (c > 9)
			c -= 7;
		res = res * 16 + c;
		i++;
	}
	return (res);
}
