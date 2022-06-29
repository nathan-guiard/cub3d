/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:53:16 by clmurphy          #+#    #+#             */
/*   Updated: 2022/06/28 13:53:27 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_my_lstadd_back(t_map **alst, t_map *new)
{
	t_map	*last;

	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last ->next != NULL)
		last = last ->next;
	last ->next = new;
}

t_map	*ft_my_lstnew(char *line)
{
	t_map	*new_node;

	new_node = (t_map *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node ->line = line;
	new_node->texture = 0;
	new_node ->next = NULL;
	return (new_node);
}
