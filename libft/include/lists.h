/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:05:29 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 13:06:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_list_int
{
	long				content;
	struct s_list_int	*next;
}	t_list_int;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **clear, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstindex(t_list *lst, int index);
void		ft_lstpop(t_list **alst, t_list *node);

t_list_int	*ft_lstnew_int(long content);
void		ft_lstadd_front_int(t_list_int **alst, t_list_int *new);
int			ft_lstsize_int(t_list_int *lst);
t_list_int	*ft_lstlast_int(t_list_int *lst);
void		ft_lstadd_back_int(t_list_int **alst, t_list_int *new);
void		ft_lstdelone_int(t_list_int *lst);
void		ft_lstclear_int(t_list_int **clear);
void		ft_lstiter_int(t_list_int *lst, void (*f)(long));
t_list_int	*ft_lstmap_int(t_list_int *lst, long (*f)(long));
void		ft_lstprint_int(t_list_int *lst);
t_list_int	*ft_lstindex_int(t_list_int *lst, int index);

#endif