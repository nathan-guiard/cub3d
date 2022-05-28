/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:39:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:45:48 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_puthex_ptr(unsigned long n)
{
	static int	i;
	char		hex[16];

	i = 0;
	ft_strlcpy(hex, HEX_MIN, 17);
	if (n < 16)
	{
		i += count_putchar(hex[n]);
		return (i);
	}
	else
	{
		count_puthex_ptr(n / 16);
		i += count_putchar(hex[n % 16]);
	}
	return (i);
}

int	count_putptr(void *n)
{
	int					count;
	unsigned long long	i;

	i = (unsigned long long)n;
	count = 0;
	if (!n)
	{
		count = count_putstr("0x0");
		return (count);
	}
	count += count_putstr("0x");
	count += count_puthex_ptr(i);
	return (count);
}
