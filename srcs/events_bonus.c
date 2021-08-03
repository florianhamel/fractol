/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:28:37 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:35:34 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color_swap(t_mlx_data *mlx_d)
{
	if (mlx_d->data->color == CHILL)
		mlx_d->data->color = PSYCHO;
	else
		mlx_d->data->color = CHILL;
	switch_frame_set(mlx_d);
}

void	switch_frame_set(t_mlx_data *mlx_d)
{
	free_arr_pix(mlx_d);
	if (mlx_d->data->set == MANDELBROT)
		mlx_d->arr_pix = mandelbrot(mlx_d->data);
	if (mlx_d->data->set == JULIA)
		mlx_d->arr_pix = julia(mlx_d->data);
	if (mlx_d->data->set == BURNING_SHIP)
		mlx_d->arr_pix = burning_ship(mlx_d->data);
	mlx_destroy_image(mlx_d->mlx_ptr, mlx_d->img_ptr);
	mlx_d->img_ptr = mlx_new_image(\
	mlx_d->mlx_ptr, mlx_d->data->win_x, mlx_d->data->win_y);
	mlx_d->img_addr = mlx_get_data_addr(\
	mlx_d->img_ptr, &(mlx_d->bpp), &(mlx_d->sl), &(mlx_d->endian));
	fill_img(mlx_d);
	mlx_put_image_to_window(\
	mlx_d->mlx_ptr, mlx_d->win_ptr, mlx_d->img_ptr, 0, 0);
}

int	key_set(int keypress, t_mlx_data *mlx_d)
{
	if (keypress == LEFT)
		move_left(mlx_d);
	if (keypress == UP)
		move_up(mlx_d);
	if (keypress == RIGHT)
		move_right(mlx_d);
	if (keypress == DOWN)
		move_down(mlx_d);
	if (keypress == COLOR_SWAP)
		color_swap(mlx_d);
	if (keypress == ESC_KEY)
	{
		mlx_destroy_image(mlx_d->mlx_ptr, mlx_d->img_ptr);
		mlx_clear_window(mlx_d->mlx_ptr, mlx_d->win_ptr);
		mlx_destroy_window(mlx_d->mlx_ptr, mlx_d->win_ptr);
		exit(0);
	}
	return (0);
}

int	zoom_set(int button, int x, int y, t_mlx_data *mlx_d)
{
	double	r_x;
	double	r_y;

	if (mlx_d->data->zoom_mode == ZOOM_MOUSE)
	{
		mlx_d->data->zoom_re = get_re_part(x, mlx_d->data);
		mlx_d->data->zoom_im = get_im_part(mlx_d->data->win_y - 1 - y, \
		mlx_d->data);
	}
	r_x = (mlx_d->data->zoom_re - mlx_d->data->ori_re) / mlx_d->data->width;
	r_y = (mlx_d->data->ori_im - mlx_d->data->zoom_im) / mlx_d->data->height;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		if (button == ZOOM_IN)
			zoom_in(mlx_d->data);
		else if (button == ZOOM_OUT)
			zoom_out(mlx_d->data);
		mlx_d->data->ori_re = mlx_d->data->zoom_re - \
		(r_x * mlx_d->data->width);
		mlx_d->data->ori_im = mlx_d->data->zoom_im + \
		(r_y * mlx_d->data->height);
		switch_frame_set(mlx_d);
	}
	return (0);
}
