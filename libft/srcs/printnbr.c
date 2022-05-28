/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:53:57 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/08 11:39:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	real_putnbrbase(long n, char *base, int count)
{
	long	nbr;
	int		i;
	int		lenbase;
	int		count;
	int		truc;

	lenbase = ft_strlen(base);
	nbr = n;
	i = 0;
	while (nbr > lenbase)
	{
		nbr /= lenbase;
		i++;
	}
	while (n > lenbase)
	{
		truc = n % (i * lenbase);
		count += count_putchar(base[truc]);
		n /= lenbase;
		i--;
	}
	count += count_putchar(base[n]);
	return (count);
}

int	count_fputnbrbase(long n, char base)
{
	int		count;

	ft_bzero(base, 17);
	count += 1;
	if (n == -9223372036854775807 && ft_strcmp(base, HEX_MAJ) == 0)
		return (count_putstr("-7FFFFFFFFFFFFFFF"));
	else if (n == -9223372036854775807 && ft_strcmp(base, HEX_MIN) == 0)
		return (count_putstr("-7fffffffffffffff"));
	if (n < 0)
	{
		count += 1;
		n *= -1;
	}
	return (real_putnbrbase(n, base, count));
}
