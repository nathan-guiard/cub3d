/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:03:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/29 12:04:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

# define TRUE	0
# define FALSE	-42

# define WIDTH	1600
# define HEIGTH	900

# define ESC 	65307

typedef enum e_status
{
	start,
}	t_status;

typedef	struct s_menu
{
	void		*init;
	void		*win;
	int			argc;
	char		**argv;
	char		*basemap;
	t_status	status;
} t_menu;

t_menu	init_menu(int argc, char **argv);
void	menu_hooks(t_menu *menu);
int		quit_everything(void);
int		key_handling(int key);

#endif