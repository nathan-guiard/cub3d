/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:17:07 by nathan            #+#    #+#             */
/*   Updated: 2021/12/02 10:18:59 by nguiard          ###   ########.fr       */
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

static int	is_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	s_end(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (is_set(set, s[i]) == 1)
		i--;
	return (i);
}

static char	*error(const char *s1, char *res, int len)
{
	if (s1 == NULL || s1[0] == '\0' || len < 1)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
		return (NULL);
	i = 0;
	res = NULL;
	res = error(s1, res, s_end(s1, set));
	if (res != NULL)
		return (res);
	while (is_set(set, s1[i]) == 1 || s1[i] == '\0')
		i++;
	res = (char *)malloc((s_end(s1, set) - i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while ((i + j) <= s_end(s1, set))
	{
		res[j] = s1[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
