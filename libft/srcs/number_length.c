/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:27 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/15 09:55:28 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_putlong(long n)
{
	static int	i;

	i = 0;
	if (n == LONG_MIN)
		return (count_putstr("-9223372036854775808"));
	if (n >= 0 && n < 10)
	{
		i += count_putchar(n + '0');
		return (i);
	}
	else if (n < 0)
	{
		count_putchar('-');
		count_putnbr(n * (-1));
		i += 1;
	}
	else
	{
		count_putnbr(n / 10);
		i += count_putchar((n % 10) + 48);
	}
	return (i);
}
