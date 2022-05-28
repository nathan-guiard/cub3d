/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:53:20 by nguiard           #+#    #+#             */
/*   Updated: 2021/11/25 17:38:07 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen(s));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

static char	*int_tab(int n, int i, int sign)
{
	char	*res;

	i += 1;
	if (sign == -1)
		i += 1;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i--;
	while (i > 0)
	{
		res[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	if (sign == -1)
		res[i] = '-';
	else
		res[i] = n + 48;
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	int		m;
	int		sign;
	char	*res;

	sign = 1;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = -1;
	n *= sign;
	m = n;
	while (m >= 10)
	{
		m /= 10;
		i++;
	}
	res = int_tab(n, i, sign);
	return (res);
}	
