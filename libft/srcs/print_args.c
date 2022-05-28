/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:24:20 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/09 08:56:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	fonction_de_merde(t_type mod, va_list plist, void **ftab)
{
	if (mod == caractere || mod == pourcent || mod == chaine)
		return (every_char(mod, plist));
	else if (mod == hexmaj)
		return (every_nbr(mod, plist, ftab[hexmaj]));
	else if (mod == hexmin)
		return (every_nbr(mod, plist, ftab[hexmin]));
	else if (mod == non_signe)
		return (every_nbr(mod, plist, ftab[non_signe]));
	else if (mod == nombre)
		return (every_nbr(mod, plist, ftab[nombre]));
	else
		return (count_putptr((void *)va_arg(plist, void *)));
}

int	every_nbr(t_type mod, va_list param_list, int (*fnc)(long))
{
	long		a;

	if (mod == non_signe)
		a = (unsigned int)va_arg(param_list, long);
	else
		a = (int)va_arg(param_list, long);
	fnc(a);
	if (mod == non_signe)
		return (u_nblen(a, 10));
	else if (mod == nombre)
		return (s_nblen(a, 10));
	else
		return (s_nblen(a, 16));
	return (0);
}

int	print_everything(const char *s, va_list plist, void **ftab)
{
	int		i;
	int		count;
	int		curr_arg;
	t_type	mod;

	curr_arg = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		mod = is_valid(s[i + 1]);
		if (s[i] == '%' && is_valid(s[i + 1]) != rien)
		{
			count += fonction_de_merde(mod, plist, ftab);
			curr_arg++;
			i += 2;
		}
		else
		{
			count += count_putchar(s[i]);
			i++;
		}
	}
	return (count);
}

int	every_char(t_type mod, va_list param_list)
{
	if (mod == caractere)
		return (count_putchar((char)va_arg(param_list, int)));
	if (mod == pourcent)
		return (count_putprct());
	if (mod == chaine)
		return (count_putstr(va_arg(param_list, char *)));
	return (0);
}
