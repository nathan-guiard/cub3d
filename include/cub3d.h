/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:03:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/11 17:33:49 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# include <math.h>

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

# define GREEN			0x0000ff00
# define BLACK			0x00000000
# define MENU_COLOR		0x0000af3f
# define SHADOW_DIFF	0x00007f2f
# define LIL_SHDW_DIFF	0x00002f1f
# define THREE_DIFF		0x00003f7f

# define TITLE_X		210
# define TITLE_Y		85

# define ANIM_LOOP		100
# define CARELAGE_LEN	50
# define CARELAGE_COLOR	0x00007070
# define CARELAGE_RATIO 10

struct	s_map;
struct	s_cub;

typedef enum e_status
{
	start,
	play,
}	t_status;

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
	t_co				last_button;
	t_status			status;
	pthread_mutex_t		*mutex_img;
	unsigned long long	base_time;
}	t_menu;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	p;
	int	end;
	int	x;
	int	y;
	int	ym;
	int	xm;
	int	err;

}	t_line;

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

typedef struct s_mlx
{
	void	*init;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_cords
{
	int		scr_width;
	int		scr_height;
	int		tile_size;
	int		scale;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	float	x;
	float	y;
	float	end_x;
	float	end_y;
	float	temp_x;
	float	temp_y;
}	t_cords;

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
	t_mlx			mlx;
}	t_cub;

/*    PARSING                 */
int		parse_map(int fd);
int		check_arguments(int ac, char **av);
int		check_chars(t_map **map, t_cub *cub);
t_cub	*init_cub(void);
int		configs_filled(t_cub *cub);
int		set_path(char *str, int *i, t_cub *cub);
int		check_first_and_last_line(char *str);
int		check_line(char *str, int ret);
int		create_map(t_map *map, t_cub *cub);
void	set_tab(char **tab, int *i, t_cub *cub, t_map *map);
int		create_list(char *line, t_map **map);
int		set_path2(char *str, char *res, t_cub *cub, int j);
/*    LIST                     */
void	ft_my_lstadd_back(t_map **alst, t_map *new);
t_map	*ft_my_lstnew(char *line);
void	ft_my_lstclear(t_map **lst);
int		ft_my_lstsize(t_map *lst);
int		ft_lst_width(t_map *map);

/*          PARSE_UTILS    */
int		ft_isset(char c, char *set);
int		ft_isspace(char *str, int *i);
char	*my_strdup(const char *s);
int		my_atoi(const char *nptr);
/*			CHECK_ERRORS	*/
int		check_arguments(int ac, char **av);
int		check_file_ext(char *file);
int		check_arguments2(int ac, char **av);

/*        CHECK_ELS        */
int		check_elems(t_map **map);
int		check_borders(t_map **map);
void	print_map(t_cub *cub);
int		compare_strings(char *s_long, char *s_short);
int		verify_borders(t_map *map, t_cub *cub);
void	check_pathnames(t_map *temp, t_cub *cub, int *i);
/*			FC_COLOR		*/
int		set_color(char *str, t_cub *cub, char c);
void	assign_rgb(char **tab, unsigned int *rgb, t_cub *cub, char c);
/*         ERROR    */
void	ft_error(t_cub *cub, t_map **map, char *str);
void	ft_error2(t_cub *cub, t_map **map, char *res, char *str);
void	ft_error_cub(t_cub *cub, t_map **map, char *str);
/*		LAUCNH_CUB3d		*/
int		launch_cub3d(t_cub *cub);
t_mlx	init_mlx(t_cub *cub);
void	my_pixel_put(t_img *img, int x, int y, int color);
/*		LET_IT_GO		*/
void	free_cub(t_cub *cub);
void	free_tab(char **s);
void	end_cub(t_cub *cub, t_map **map);
/*		KEYS			*/
int		ft_close(t_cub *cub);
void	set_hooks(t_cub *cub);
int		check_key(int keycode, t_cub *cub);
/*		MINI MAP		*/
int		draw_mini_map(t_cub *cub);
/*		BRES		*/
void	ft_bresenham(t_cords *cords, t_cub *cub);
void	set_data(t_cords *cords, t_line *data);
void	ft_bresenham_bis(t_cords *cords, t_cub *cub, t_line *data);
int		draw_grid(t_cub *cub, t_cords *cords, int fill);
int		full_square(t_cords *cords, t_cub *cub, int fill);

#endif
