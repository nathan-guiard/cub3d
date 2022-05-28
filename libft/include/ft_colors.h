/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:48:27 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/05 12:48:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_colors */
#ifndef FT_COLORS_H
# define FT_COLORS_H

# define C_BOLD 1
# define C_FADED 2
# define C_ITALIC 3
# define C_UNDERLINE 4
# define C_BLINK 5
# define C_BLINKOFF 25
# define C_REVERSE 7
# define C_HIDE 8
# define C_CROSSED 9

# define C_BLACK 0
# define C_RED 1
# define C_GREEN 2
# define C_YELLOW 3
# define C_BLUE 4
# define C_MAGENTA 5
# define C_CYAN 6
# define C_WHITE 7
# define C_GREY 8
# define C_HBLACK 8
# define C_HRED 9
# define C_HGREN 10
# define C_HYELLOW 11
# define C_HBLUE 12
# define C_HMAGENTA 13
# define C_HCYAN 14
# define C_HWHITE 15

# define C_RESET 42000

# define C_BASE "\033["
# define C_BG "48;5;"
# define C_FG "38;5;"
# define C_BGRESET "49;"
# define C_FGRESET "39m"

/* Fonctions de base */
void		set_layout(unsigned int fg, unsigned int bg, unsigned int style);
void		delete_std(int n);

/* Need printf */
void		set_layout_printf(unsigned int fg,
				unsigned int bg, unsigned int style);
void		delete_std_printf(int n);
void		loading_bar(int progression);

#endif