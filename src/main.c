/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:58:01 by alrodri2          #+#    #+#             */
/*   Updated: 2023/11/09 11:44:38 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_exit(t_fractstruct *fr)
{
	void(fr);
	if (fr->argc != 2)
		write(1, "Please, specify if mandelbort or julia\n", 39);
	exit((write(1, "Window Closed\n", 15) * 0));
}

int	main(int argc, char **argv)
{
	t_fractstruct	fr;

	fr.argc = argc;
	if (argc != 2)
		ft_exit(&fr);
	fr.bpp = 0;
	fr.l_len = 0;
	fr.addr = NULL;
	fr.mlx = mlx_init();
	fr.win = mlx_new_window(fr.mlx, HIGH, WIDTH, "Chupame esta");
	fr.img = mlx_new_image(fr.mlx, HIGH, WIDTH);
	fr.addr = mlx_get_data_addr(fr.img, &fr.bpp, &fr.l_len, &fr.end);
	f.min_re = -2.0;
	f.max_re = 2.0;
	f.min_im = -2.0;
	f.max_im = f.min_re + (f.max_re - (f.min_re)) * HIGH / WIDTH;
	render(&fr, -1, -1);
	


	return(1);
}