/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:06:24 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:22:47 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_julia(t_comp z0, t_data *data)
{
	int	max_iter;
	int	iter;

	max_iter = 120;
	iter = 0;
	while (iter < max_iter && modulus(z0) < 3)
	{
		z0 = z_next(z0, data->c);
		iter++;
	}
	if (modulus(z0) < 3)
		return (0);
	if (data->color == CHILL)
		return (get_divergence_color(iter, max_iter));
	return (get_divergence_color_map(iter));
}

int	get_pix_julia(int y, int x, t_data *data)
{
	t_comp	z0;
	int		color;

	z0.re = get_re_part(x, data);
	z0.im = get_im_part(y, data);
	color = get_color_julia(z0, data);
	return (color);
}

int	**julia(t_data *data)
{
	int		**arr_pix;
	int		y;
	int		x;

	arr_pix = init_arr_pix(data);
	y = 0;
	while (y < data->win_y)
	{
		x = 0;
		while (x < data->win_x)
		{
			arr_pix[data->win_y - 1 - y][x] = get_pix_julia(y, x, data);
			x++;
		}
		y++;
	}
	return (arr_pix);
}

void	start_julia(char **av, int zoom_mode)
{
	t_data		*data;
	t_mlx_data	*mlx_d;

	data = init_data(JULIA, zoom_mode);
	data->zoom_im = 0.1;
	(data->c).re = get_param(av[2]);
	(data->c).im = get_param(av[3]);
	data->zoom_im = -data->zoom_im;
	mlx_d = init_mlx_data(data);
	mlx_d->arr_pix = julia(data);
	fill_img(mlx_d);
	mlx_put_image_to_window(mlx_d->mlx_ptr, mlx_d->win_ptr, \
	mlx_d->img_ptr, 0, 0);
	mlx_hook(mlx_d->win_ptr, MOUSE_EVENT, (1L << 2), zoom, mlx_d);
	mlx_hook(mlx_d->win_ptr, WIN_QUIT, NO_MASK, win_quit, mlx_d);
	mlx_hook(mlx_d->win_ptr, KEY_PRESS, (1L << 0), win_esc, mlx_d);
	mlx_loop(mlx_d->mlx_ptr);
}
