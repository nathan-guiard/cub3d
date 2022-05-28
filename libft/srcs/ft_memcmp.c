/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:43:44 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/02 09:28:26 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bs1;
	unsigned char	*bs2;

	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (bs1[i] != bs2[i])
		{
			return (bs1[i] - bs2[i]);
		}
		i++;
	}
	return (0);
}
