/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:41:11 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 13:09:23 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include "libft.h"

/* get_next_line */
char		*get_next_line(int fd);
char		*get_line(char *s, int i);
char		*new_rest(char *rest);
char		*read_until_newline(int fd, char *rest);
char		*the_line(char *s);

/* Utils */
char		*ft_strchr_g(const char *s, int c);
char		*join_gnl(char *s1, char *s2);

#endif