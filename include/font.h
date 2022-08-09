/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:56 by nguiard           #+#    #+#             */
/*   Updated: 2022/08/09 09:56:43 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H

typedef struct s_co
{
	int	x;
	int	y;
	int	color;
}	t_co;

typedef struct s_img
{
	void	*img;
	char 	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

void	ft_a(t_img *img, t_co co, int size);
void	ft_b(t_img *img, t_co co, int size);
void	ft_c(t_img *img, t_co co, int size);
void	ft_d(t_img *img, t_co co, int size);
void	ft_e(t_img *img, t_co co, int size);
void	ft_f(t_img *img, t_co co, int size);
void	ft_g(t_img *img, t_co co, int size);
void	ft_h(t_img *img, t_co co, int size);
void	ft_i(t_img *img, t_co co, int size);
void	ft_j(t_img *img, t_co co, int size);
void	ft_k(t_img *img, t_co co, int size);
void	ft_l(t_img *img, t_co co, int size);
void	ft_m(t_img *img, t_co co, int size);
void	ft_n(t_img *img, t_co co, int size);
void	ft_o(t_img *img, t_co co, int size);
void	ft_p(t_img *img, t_co co, int size);
void	ft_q(t_img *img, t_co co, int size);
void	ft_r(t_img *img, t_co co, int size);
void	ft_s(t_img *img, t_co co, int size);
void	ft_t(t_img *img, t_co co, int size);
void	ft_u(t_img *img, t_co co, int size);
void	ft_v(t_img *img, t_co co, int size);
void	ft_w(t_img *img, t_co co, int size);
void	ft_x(t_img *img, t_co co, int size);
void	ft_y(t_img *img, t_co co, int size);
void	ft_z(t_img *img, t_co co, int size);
void	ft_0(t_img *img, t_co co, int size);
void	ft_1(t_img *img, t_co co, int size);
void	ft_2(t_img *img, t_co co, int size);
void	ft_3(t_img *img, t_co co, int size);
void	ft_4(t_img *img, t_co co, int size);
void	ft_5(t_img *img, t_co co, int size);
void	ft_6(t_img *img, t_co co, int size);
void	ft_7(t_img *img, t_co co, int size);
void	ft_8(t_img *img, t_co co, int size);
void	ft_9(t_img *img, t_co co, int size);
void	ft_dot(t_img *img, t_co co, int size);
void	ft_slash(t_img *img, t_co co, int size);

void	mlx_putstr(t_img *img, char *str, t_co co, int size);

#endif
