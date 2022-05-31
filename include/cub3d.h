/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:03:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/31 17:19:31 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "font.h"

# define TRUE			0
# define FALSE			-42

# define WIDTH			1200
# define HEIGTH			900

# define DIR_X			0
# define DIR_Y			1
# define DOWNSIDE		0
# define UPSIDE			1
# define MENU_BUTTONS	2

# define ESC 			65307
# define PLUS			61
# define MINUS			45
# define ENTER			65293
# define LEFT_KEY		65361
# define RIGHT_KEY		65363
# define UP_KEY			65362
# define DOWN_KEY		65364
# define A_KEY			97
# define W_KEY			119
# define D_KEY			100
# define S_KEY			115

# define GREEN			0x0000ff00
# define BLACK			0x00000000
# define MENU_COLOR		0x0000af3f
# define SHADOW_DIFF	0x00007f2f
# define LIL_SHDW_DIFF	0x00003f1f
# define THREE_DIFF		0x00003f7f

typedef enum e_status
{
	start,
}	t_status;

typedef	struct s_menu
{
	void		*init;
	void		*win;
	t_img		img;
	int			argc;
	int			button;
	char		**argv;
	char		*basemap;
	t_co		last_button;
	t_status	status;
}	t_menu;

t_menu	init_menu(int argc, char **argv);
void	menu_hooks(t_menu *menu);
int		quit_everything(void);
int		key_handling(int key, void *arg);
void	start_handling(int key, t_menu *menu);

/*	Menu drawing			*/
void	draw_button(t_menu *menu, int key);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	straight_line(t_img *img, t_co start, int len, 
				int direction);
void	diagonale(t_img *img, t_co start, int len, int direction);
void	draw_borders(t_img *img, t_co co);
void	remove_border(t_img *img, t_co co);
void	draw_first_menu(t_menu *menu);
void	draw_releif(t_img *img, t_co co, int size);

#endif
