/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:58:01 by alrodri2          #+#    #+#             */
/*   Updated: 2023/12/18 18:22:14 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_exit(t_fractstruct *fr)
{
	(void)fr;
	if (fr->argc != 2)
		write(1, "Please, specify if mandelbort or julia\n", 39);
	exit((write(1, "Window Closed\n", 15) * 0));
}

int	ft_key(int key, t_fractstruct *fr)
{
	if (key == 53)
		ft_exit(fr);
	if (key == 4)
	{
		write(1, "up\n", 3);
		fr->max_im *= 1.1;
	}
	return (1);
	
}

int	ft_mouse(int key, int x, int y, t_fractstruct *fr)
{
	fr->cen_re = fr->min_re - fr->max_re;
	fr->cen_im = fr->max_im - fr->min_im;
	if (key == 1)
	{
		fr->m_x = -2.0 + (double)x * (2.0 - (-2.0)) / WIDTH;
		fr->m_y = fr->max_im + (double)y * (-2.0 - fr->max_im) / WIDTH;
	}
	if (key == 4)
	{
		fr->max_re = fr->max_re + (fr->cen_re - 1.1 * fr->cen_re) / 2;
		fr->min_re = fr->max_re + 1.1 * fr->cen_re;
		fr->min_im = fr->min_im + (fr->cen_im - 1.1 * fr->cen_im) / 2;
		fr->max_im = fr->min_im + 1.1 * fr->cen_im;
	}
	if (key == 5)
	{
		fr->max_re = fr->max_re + (fr->cen_re - 0.9 * fr->cen_re) / 2;
		fr->min_re = fr->max_re + 0.9 * fr->cen_re;
		fr->min_im = fr->min_im + (fr->cen_im - 0.9 * fr->cen_im) / 2;
		fr->max_im = fr->min_im + 0.9 * fr->cen_im;
	}
	return (render(fr, -1, -1));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
		i++;
	if (n == 0)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	main(int argc, char **argv)
{
	t_fractstruct	fr;

	fr.argc = argc;
	fr.args = argv[1];
	if (argc != 2)
		ft_exit(&fr);
	fr.bpp = 0;
	fr.l_len = 0;
	fr.addr = NULL;
	fr.mlx = mlx_init();
	fr.win = mlx_new_window(fr.mlx, HIGH, WIDTH, "Chupame esta");
	fr.img = mlx_new_image(fr.mlx, HIGH, WIDTH);
	fr.addr = mlx_get_data_addr(fr.img, &fr.bpp, &fr.l_len, &fr.end);
	fr.min_re = -2.0;
	fr.max_re = 2.0;
	fr.min_im = -2.0;
	fr.max_im = 2.0;
	render(&fr, -1, -1);
	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);
	mlx_hook (fr.win, 17, 0, ft_exit, &fr);
	mlx_key_hook (fr.win, ft_key, &fr);
	mlx_mouse_hook (fr.win, ft_mouse, &fr);
	mlx_loop (fr.mlx);
	
	


	return(1);
}