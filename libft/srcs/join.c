/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:07:58 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 13:12:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	strjoin mais en mieux, qui free s1 et s2	*/
char	*join(char *s1, char *s2)
{
	char	*res;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
	{
		s2 = malloc(sizeof(char));
		if (!s2)
			return (NULL);
		s2[0] = '\0';
	}
	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}
