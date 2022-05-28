/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:54:23 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/15 09:32:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*buff;

	if (!lst)
	{
		return ;
	}
	buff = lst;
	while (buff->next != NULL)
	{
		(*f)(buff->content);
		buff = buff->next;
	}
	(*f)(buff->content);
}

void	ft_lstiter_int(t_list_int *lst, void (*f)(long))
{
	t_list_int	*buff;

	if (!lst)
	{
		return ;
	}
	buff = lst;
	while (buff->next != NULL)
	{
		(*f)(buff->content);
		buff = buff->next;
	}
	(*f)(buff->content);
}
