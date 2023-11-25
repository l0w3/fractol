/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:08:42 by alrodri2          #+#    #+#             */
/*   Updated: 2023/11/09 11:36:24 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./MinilibX/mlx.h"
# include <stdio.h>

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



#endif