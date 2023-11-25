/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:57:57 by alrodri2          #+#    #+#             */
/*   Updated: 2023/11/09 12:20:24 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int type_fractal(t_fractstruct *fr, double re, double im)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (fr->args[len])
        ++len;
    fr->args[len] = '\0';
    if (!ft_strncmp(fr->args[1], "mandelbrot", -1))
        i = mandelbrot(re, im, fr);
    else if(!ft_strncmp(fr->args[1], "julia", -1))
        i = julia(re, im, fr);
    else
    {
        write(1, "Check ur spelling mate\n", 24);
        ft_exit(fr);
    }
    return (i);
}

void	my_mlx_pixel_put(t_fractstruct *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int render(t_fractstruct *fr, int x, int y)
{
    double  re;
    double  im;
    int     i;

    fr->max_iter = 100;
    mlx_clear_window(fr->mlx, fr->win);
    while (++y < HIGH)
    {
        x = -1
        while (++x < WIDTH)
        {
            re = f->min_re + (double)x * (f->max_re - (f->min_re)) / WIDTH;
			im = f->max_im + (double)y * (f->min_im - f->max_im) / HIGH;
            i = type_fractal(fr, re, im);
            if (i < fr->max_iter)
                my_mlx_pixel_put(fr, x, y, (i * 0x6592bf));
            else
                my_mlx_pixel_put(fr, x, y, 0x000000);
        }
    }
    mlx_put_image_to_windows(fr->mlx, fr->win, fr->img, 0, 0);
    return (0);
}