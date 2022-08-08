/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:03:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/08 16:59:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "libft.h"
# include "mlx.h"
# include "font.h"
# include "pthread.h"
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <dirent.h>
# include <stdbool.h>

# define TRUE			0
# define FALSE			-42
# define ERROR			-420

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
# define DEL			65288

# define GREEN			0x0000ff00
# define BLACK			0x00000000
# define MENU_COLOR		0x0000af3f
# define SHADOW_DIFF	0x00007f2f
# define LIL_SHDW_DIFF	0x00002f1f
# define THREE_DIFF		0x00003f7f
# define THREE_BLUE		MENU_COLOR + THREE_DIFF
# define PLAYER_COLOR	GREEN

# define TITLE_X		210
# define TITLE_Y		85

# define ANIM_LOOP		100
# define CARELAGE_LEN	50
# define CARELAGE_COLOR	0x00007070
# define CARELAGE_RATIO 10

# define MAX_STR_LEN	14

# define MAX_ROW		13
# define MAX_COL		22

typedef enum e_status
{
	start = 1,
	play = 2,
	editor = 10,
	editor_ask_name = 11,
	editor_building = 12,
}	t_status;

typedef struct s_flags
{
	int	n;
	int s;
	int	e;
	int	w;
}	t_flags;

typedef struct s_menu
{
	void				*init;
	void				*win;
	t_img				img;
	int					argc;
	int					button;
	int					key_pressed;
	char				**argv;
	char				*basemap;
	t_co				button_co;
	t_status			status;
	pthread_mutex_t		*mutex_img;
	unsigned long long	base_time;
	char				**char_map;
	int					fd;
}	t_menu;

typedef struct s_bres
{
	int	x;
	int	x1;
	int	x2;
	int	y;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	e;
	int	e10;
	int	e01;
}	t_bres;

typedef struct s_set
{
	t_co	a;
	t_co	b;
}	t_set;

typedef struct s_math
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_math;

typedef struct s_map
{
	char			*line;
	int				len;
	struct s_map	*next;
}	t_map;

typedef struct s_cub
{
	int				width;
	int				height;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	unsigned int	f_color;
	unsigned int	c_color;
	struct s_map	*map;
	char			**char_map;
}	t_cub;

t_menu	init_menu(int argc, char **argv);
void	menu_hooks(t_menu *menu);
int		quit_everything(void);
int		key_handling(int key, void *arg);
void	start_handling(int key, t_menu *menu);

unsigned long long	get_elapsedtime(unsigned long long base);

/*	Menu drawing			*/
void	draw_menu_button(t_menu *menu, int key);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	straight_line(t_img *img, t_co start, int len, \
				int direction);
void	diagonale(t_img *img, t_co start, int len, int direction);
void	draw_borders(t_img *img, t_co co);
void	remove_border(t_img *img, t_co co);
void	draw_first_menu(t_menu *menu);
void	draw_releif(t_img *img, t_co co, int size);
void	draw_menu(t_menu *menu);

void	carelage(t_menu *menu, int frame);
void	put_carelage_x(t_menu *menu);
void	draw_box(t_menu *menu, t_co start, t_co end);

/*	Animation				*/
void	*menu_bg_animation(void *menu);
void	menu_bg_line(t_img img, t_co start, t_co end);
t_math	init_mathline(t_set set);
t_co	base_set(t_set set);
int		check_base(t_set set, t_co base);
int		animation_thread(void *arg);

/*	Play menu				*/
void	play_handling(t_menu *menu, int key);
void	draw_play(t_menu *menu);
t_list	*get_map_list(void);
int roulette(t_menu *menu, t_list *lst, int key, int index);
void	put_play_maps(t_menu *menu, char **tab);
char	**define_map_tab(t_list *lst, int index);
char	*treated_string(char *str);
void	custom_free_tabtab(char **tab);
t_list	*destroy_map_list(t_list *lst);
int		exec_map(t_list *lst, int index);

/*	Editor					*/
void	editor_handling(t_menu *menu, int key);
void	draw_ask_name(t_menu *menu);
char	*ask_name_handling(t_menu *menu, int key, char *last);
void	init_editor(t_menu *menu, char *last);
void	draw_editor(t_menu *menu, char *map);
void	init_charmap(t_menu *menu);
void	draw_charmap(t_menu *menu);
void	build_handling(t_menu *menu, int key);
void	draw_wall_square(t_menu *menu, t_co co);
void	draw_player(t_menu *menu, char key, int x, int y);

#endif
