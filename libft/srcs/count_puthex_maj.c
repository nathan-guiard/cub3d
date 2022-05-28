/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_puthex_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:40:34 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:45:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_puthex_maj(unsigned int n)
{
	static int	i;
	char		hex[16];

	ft_strlcpy(hex, HEX_MAJ, 17);
	i = 0;
	if (n < 16)
	{
		i += count_putchar(hex[n]);
		return (i);
	}
	else
	{
		count_puthex_maj(n / 16);
		i += count_putchar(hex[n % 16]);
	}
	return (i);
}
