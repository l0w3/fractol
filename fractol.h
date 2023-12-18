/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:08:42 by alrodri2          #+#    #+#             */
/*   Updated: 2023/12/18 18:10:42 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./MinilibX/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fracstruct
{
    int			bpp;
	int			l_len;
	int			end;
    char		*addr;
    void		*mlx;
	void		*win;
	void		*img;
	double		m_x;
	double		m_y;
	int			max_iter;
	double		cen_re;
	double		cen_im;
	double		max_im;
	double		min_im;
	double		min_re;
	double		max_re;
	int         argc;
	char		*args;
}   t_fractstruct;
# define HIGH 800
# define WIDTH 800

// render.c
int 	type_fractal(t_fractstruct *fr, double re, double im);
void	my_mlx_pixel_put(t_fractstruct *data, int x, int y, int color);
int 	render(t_fractstruct *fr, int x, int y);
// main.c
int	ft_exit(t_fractstruct *fr);
int	ft_key(int key, t_fractstruct *fr);
int	ft_mouse(int key, int x, int y, t_fractstruct *fr);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif