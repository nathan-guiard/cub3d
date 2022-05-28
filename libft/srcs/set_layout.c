/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:27:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/11 13:10:42 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_c(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_c(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_c(s[i]);
		i++;
	}
}

void	ft_putnbr_c(unsigned int n)
{
	if (n < 10)
	{
		ft_putchar_c(n + '0');
	}
	else
	{
		ft_putnbr_c(n / 10);
		ft_putnbr_c(n % 10);
	}
}		

void	set_layout(unsigned int fg, unsigned int bg, unsigned int style)
{
	ft_putstr_c(C_BASE);
	if (style == C_RESET)
		style = 0;
	ft_putnbr_c(style);
	ft_putchar_c(';');
	if (bg == C_RESET)
		ft_putstr_c(C_BGRESET);
	else
	{
		ft_putstr_c(C_BG);
		ft_putnbr_c(bg);
		ft_putchar_c(';');
	}
	if (fg == C_RESET)
		ft_putstr_c(C_FGRESET);
	else
	{
		ft_putstr_c(C_FG);
		ft_putnbr_c(fg);
		ft_putchar_c('m');
	}
}

void	delete_std(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_c('\b');
		i++;
	}
}
