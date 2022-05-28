/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:23:35 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/15 09:31:54 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
	{
		return (NULL);
	}
	a->content = content;
	a->next = NULL;
	return (a);
}

t_list_int	*ft_lstnew_int(long content)
{
	t_list_int	*a;

	a = malloc(sizeof(t_list_int));
	if (!a)
	{
		return (NULL);
	}
	a->content = content;
	a->next = NULL;
	return (a);
}
