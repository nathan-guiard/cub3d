/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:44:04 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:58:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/* Enum t_type */
typedef enum e_type
{
	rien = 0,
	nombre = 1,
	caractere = 2,
	non_signe = 3,
	pointeur = 4,
	hex_min = 5,
	hex_maj = 6,
	pourcent = 7,
	chaine = 8,
	binaire = 9,
	long_int = 10,
}	t_type;

/* Variables */
# define HEX_MIN "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define DEC "0123456789"
# define TYPES "cspdiuxX%"

/* Parsing */
t_type		*printf_parsing(const char *s);
t_type		is_valid(char c);

/* Print arguments */
int			count_putstr(char *s);
int			count_putchar(char c);
int			count_putunsigned(unsigned int n);
int			count_puthex_min(unsigned int n);
int			count_puthex_maj(unsigned int n);
int			count_putprct(void);
int			count_putnbr(int n);
int			count_putptr(void *n);
int			count_putbin(unsigned int n);
int			count_putlong(long n);

/* PRINTF */
int			ft_printf(const char *s, ...);
#endif