/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_layout_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:04:02 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/11 13:09:22 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_layout_printf(unsigned int fg, unsigned int bg, unsigned int style)
{
	if (style == C_RESET)
		style = 0;
	printf("%s%d;", C_BASE, style);
	if (bg == C_RESET)
		printf("%s", C_BGRESET);
	else
		printf("%s%d;", C_BG, bg);
	if (fg == C_RESET)
		printf("%s", C_FGRESET);
	else
		printf("%s%dm", C_FG, fg);
}

void	delete_std_printf(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("\b");
		i++;
	}
}
