/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 22:17:50 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 20:51:17 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	exit_usage_bonus(int error)
{
	if (error == USAGE)
		printf("usage:\n- mandelbrot: ./fractol [-m]\n\
- julia: ./fractol [-j re im]\n\
Examples: [-0.8 +0.156] [-0.4 +0.6]  [+0.285 +0.01]\n\
- burning ship: ./fractol [--bonus]\n");
	if (error == PARAMS)
		printf("julia: invalid parameters:\n\
re and im in range ]-100 ; 100[ with max precision of 1.0E-10,\n\
Examples: [-0.8 +0.156] [-0.4 +0.6]  [+0.285 +0.01]\n");
	exit(error);
}

void	start_julia_set(char **av, int zoom_mode)
{
	t_data		*data;
	t_mlx_data	*mlx_d;

	data = init_data(JULIA, zoom_mode);
	(data->c).re = get_param(av[2]);
	(data->c).im = get_param(av[3]);
	mlx_d = init_mlx_data(data);
	mlx_d->arr_pix = julia(data);
	fill_img(mlx_d);
	mlx_put_image_to_window(mlx_d->mlx_ptr, mlx_d->win_ptr, \
	mlx_d->img_ptr, 0, 0);
	mlx_hook(mlx_d->win_ptr, MOUSE_EVENT, (1L << 2), zoom_set, mlx_d);
	mlx_hook(mlx_d->win_ptr, WIN_QUIT, NO_MASK, win_quit, mlx_d);
	mlx_hook(mlx_d->win_ptr, KEY_PRESS, (1L << 0), key_set, mlx_d);
	mlx_loop(mlx_d->mlx_ptr);
}

void	start_mandelbrot_set(int zoom_mode)
{
	t_data		*data;
	t_mlx_data	*mlx_d;

	data = init_data(MANDELBROT, zoom_mode);
	data->ori_im = 1;
	data->height = 2;
	data->width = 3;
	data->color = PSYCHO;
	mlx_d = init_mlx_data(data);
	mlx_d->arr_pix = mandelbrot(data);
	fill_img(mlx_d);
	mlx_put_image_to_window(\
	mlx_d->mlx_ptr, mlx_d->win_ptr, mlx_d->img_ptr, 0, 0);
	mlx_hook(mlx_d->win_ptr, MOUSE_EVENT, (1L << 2), zoom_set, mlx_d);
	mlx_hook(mlx_d->win_ptr, WIN_QUIT, NO_MASK, win_quit, mlx_d);
	mlx_hook(mlx_d->win_ptr, KEY_PRESS, (1L << 0), key_set, mlx_d);
	mlx_loop(mlx_d->mlx_ptr);
}
