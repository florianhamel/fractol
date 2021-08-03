/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:28:55 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:44:43 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_comp	z_next_b(t_comp z, t_comp c)
{
	t_comp	z_next;

	z.re = fabsl(z.re);
	z.im = fabsl(z.im);
	z_next.re = powl(z.re, 2) - powl(z.im, 2);
	z_next.im = 2 * z.re * z.im;
	z_next.re += c.re;
	z_next.im += c.im;
	return (z_next);
}

int	get_color_burning_ship(t_comp c, t_data *data)
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
		z = z_next_b(z, c);
		iter++;
	}
	if (modulus(z) < 3)
		return (0xffffff);
	if (data->color == CHILL)
		return (get_divergence_color(iter, max_iter));
	return (get_divergence_color_map(iter));
}

int	get_pix_burning_ship(int y, int x, t_data *data)
{
	t_comp	c;
	int		color;

	c.re = get_re_part(x, data);
	c.im = get_im_part(y, data);
	color = get_color_burning_ship(c, data);
	return (color);
}

int	**burning_ship(t_data *data)
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
			arr_pix[data->win_y - 1 - y][x] = get_pix_burning_ship(y, x, data);
			x++;
		}
		y++;
	}
	return (arr_pix);
}

void	start_burning_ship(int zoom_mode)
{
	t_data		*data;
	t_mlx_data	*mlx_d;

	data = init_data(BURNING_SHIP, zoom_mode);
	mlx_d = init_mlx_data(data);
	mlx_d->data->ori_re = -1.862;
	mlx_d->data->width = 0.2;
	mlx_d->data->ori_im = 0.05;
	mlx_d->data->height = 0.15;
	mlx_d->arr_pix = burning_ship(data);
	fill_img(mlx_d);
	mlx_put_image_to_window(\
	mlx_d->mlx_ptr, mlx_d->win_ptr, mlx_d->img_ptr, 0, 0);
	mlx_hook(mlx_d->win_ptr, MOUSE_EVENT, (1L << 2), zoom_set, mlx_d);
	mlx_hook(mlx_d->win_ptr, WIN_QUIT, NO_MASK, win_quit, mlx_d);
	mlx_hook(mlx_d->win_ptr, KEY_PRESS, (1L << 0), key_set, mlx_d);
	mlx_loop(mlx_d->mlx_ptr);
}
