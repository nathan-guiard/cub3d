/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/02 10:03:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buff;

	if (!lst)
		return (NULL);
	buff = lst;
	while (buff->next != NULL)
	{
		buff = buff->next;
	}
	return (buff);
}

t_list_int	*ft_lstlast_int(t_list_int *lst)
{
	t_list_int	*buff;

	if (!lst)
		return (NULL);
	buff = lst;
	while (buff->next != NULL)
	{
		buff = buff->next;
	}
	return (buff);
}
