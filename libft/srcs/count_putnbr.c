/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:27 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:45:42 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_putnbr(int n)
{
	static int	i;

	i = 0;
	if (n == -2147483648)
		return (count_putstr("-2147483648"));
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
