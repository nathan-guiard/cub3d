/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:34:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:45:50 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_putstr(char *s)
{
	int	i;

	if (!s)
		return (count_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		count_putchar(s[i]);
		i++;
	}
	return (i);
}
