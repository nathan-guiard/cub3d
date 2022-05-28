/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:25:39 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/11 13:09:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_braille(int i)
{
	if (i < 0 || i > 6)
	{
		printf("?");
		return ;
	}
	if (i == 0)
		printf(" ");
	if (i == 1)
		printf("⠄");
	if (i == 2)
		printf("⠆");
	if (i == 3)
		printf("⠇");
	if (i == 4)
		printf("⠧");
	if (i == 5)
		printf("⠷");
	if (i == 6)
		printf("⠿");
}

static void	print_fullbar(void)
{
	printf("█████████████████");
}

static void	print_spaces(int i, int progression)
{
	if (progression > 96)
	{
		print_braille(progression % 6);
		i = 100;
	}
	while (i < 97)
	{
		printf(" ");
		i += 6;
	}
}

void	loading_bar(int progression)
{
	int	i;

	i = 0;
	if (progression >= 100)
	{
		print_fullbar();
		return ;
	}
	while (i < progression / 6)
	{
		printf("⠿");
		i++;
	}
	i *= 6;
	if (progression < 96)
		print_braille(progression % 6);
	if (i < 96)
		i += 6;
	print_spaces(i, progression);
}
