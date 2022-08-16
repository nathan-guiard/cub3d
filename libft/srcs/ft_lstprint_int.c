/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:23:14 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:52:23 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_int(t_list_int *lst)
{
	t_list_int	*buff;

	if (!lst)
	{
		ft_printf("La liste est vide\n");
		return ;
	}
	buff = lst;
	while (buff)
	{
		ft_printf("%l\n", buff->content);
		buff = buff->next;
	}
}
