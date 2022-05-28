/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:02:21 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/15 09:32:22 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buff;
	t_list	*res;

	res = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		buff = ft_lstnew((f)(lst->content));
		if (!buff)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, buff);
		lst = lst->next;
	}
	return (res);
}

t_list_int	*ft_lstmap_int(t_list_int *lst, long (*f)(long))
{
	t_list_int	*buff;
	t_list_int	*res;

	res = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		buff = ft_lstnew_int((f)(lst->content));
		if (!buff)
		{
			ft_lstclear_int(&res);
			return (NULL);
		}
		ft_lstadd_back_int(&res, buff);
		lst = lst->next;
	}
	return (res);
}
