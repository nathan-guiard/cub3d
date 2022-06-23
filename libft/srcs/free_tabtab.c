/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tabtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:03:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/06/23 22:08:34 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	free() un double tableau de n'importe quelle sorte	*/
void	free_tabtab(char **dtab)
{
	int	i;

	i = 0;
	while (dtab[i])
	{
		free(dtab[i]);
		i++;
	}
	free(dtab);
}
