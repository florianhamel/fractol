/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:51:36 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 17:36:09 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_mandelbrot(t_comp c, t_data *data)
{
	t_comp	z;
	int		max_iter;
	int		iter;

	z.re = 0;
	z.im = 0;
	max_iter = 120;
	iter = 0;
	while (iter < max_iter && modulus(z) < 3)
	{
		z = z_next(z, c);
		iter++;
	}
	if (modulus(z) < 3)
		return (0xffffff);
	if (data->color == CHILL)
		return (get_divergence_color(iter, max_iter));
	return (get_divergence_color_map(iter));
}

int	get_pix_mandelbrot(int y, int x, t_data *data)
{
	t_comp	c;
	int		color;

	c.re = get_re_part(x, data);
	c.im = get_im_part(y, data);
	color = get_color_mandelbrot(c, data);
	return (color);
}

int	**mandelbrot(t_data *data)
{
	int	**arr_pix;
	int	y;
	int	x;

	arr_pix = init_arr_pix(data);
	y = 0;
	while (y < data->win_y)
	{
		x = 0;
		while (x < data->win_x)
		{
			arr_pix[data->win_y - 1 - y][x] = get_pix_mandelbrot(y, x, data);
			x++;
		}
		y++;
	}
	return (arr_pix);
}

void	start_mandelbrot(int zoom_mode)
{
	t_data		*data;
	t_mlx_data	*mlx_d;

	data = init_data(MANDELBROT, zoom_mode);
	data->ori_im = 1;
	data->height = 2;
	data->width = 3;
	data->zoom_re = -0.761574;
	data->zoom_im = -0.0847596;
	data->zoom_im = -data->zoom_im;
	data->color = PSYCHO;
	mlx_d = init_mlx_data(data);
	mlx_d->arr_pix = mandelbrot(data);
	fill_img(mlx_d);
	mlx_put_image_to_window(\
	mlx_d->mlx_ptr, mlx_d->win_ptr, mlx_d->img_ptr, 0, 0);
	mlx_hook(mlx_d->win_ptr, MOUSE_EVENT, (1L << 2), zoom, mlx_d);
	mlx_hook(mlx_d->win_ptr, WIN_QUIT, NO_MASK, win_quit, mlx_d);
	mlx_hook(mlx_d->win_ptr, KEY_PRESS, (1L << 0), win_esc, mlx_d);
	mlx_loop(mlx_d->mlx_ptr);
}
