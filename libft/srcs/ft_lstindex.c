/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:46 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/02 14:09:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Le miallon donne est le maillon numero 0,
**	si index est plus grand que la taille de
**	la liste, renvoie le dernier element	 */
t_list	*ft_lstindex(t_list *lst, int index)
{
	t_list	*buff;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	buff = lst;
	while (buff->next != NULL && i < index)
	{
		buff = buff->next;
		i++;
	}
	return (buff);
}

/*	Le miallon donne est le maillon numero 0,
**	si index est plus grand que la taille de
**	la liste, renvoie le dernier element	 */
t_list_int	*ft_lstindex_int(t_list_int *lst, int index)
{
	t_list_int	*buff;
	int			i;

	i = 0;
	if (!lst)
		return (NULL);
	buff = lst;
	while (buff->next != NULL && i < index)
	{
		buff = buff->next;
		i++;
	}
	return (buff);
}
