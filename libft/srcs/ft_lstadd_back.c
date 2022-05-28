/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/02 11:31:08 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*buff;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	buff = ft_lstlast(*alst);
	buff->next = new;
}

void	ft_lstadd_back_int(t_list_int **alst, t_list_int *new)
{
	t_list_int	*buff;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	buff = ft_lstlast_int(*alst);
	buff->next = new;
}
