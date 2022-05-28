/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:36:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:45:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_putunsigned(unsigned int n)
{
	static int	i;

	i = 0;
	if (n < 10)
	{
		i += count_putchar(n + '0');
		return (i);
	}
	else
	{
		count_putunsigned(n / 10);
		i += count_putchar((n % 10) + 48);
	}
	return (i);
}
