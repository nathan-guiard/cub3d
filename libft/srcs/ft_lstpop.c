/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:08 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:20:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **alst, t_list *node)
{
	t_list	*following;
	t_list	*buff;
	t_list	*before;

	if (!alst || !(node->content) || !node)
		return ;
	buff = *alst;
	before = NULL;
	while (buff)
	{
		if (buff == node)
		{
			following = node->next;
			if (before)
				before->next = following;
			else
				*alst = following;
			break ;
		}
		before = buff;
		buff = buff->next;
	}
}
