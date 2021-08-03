/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:51:53 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 14:57:45 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	win_quit(t_mlx_data *mlx_d)
{
	mlx_destroy_image(mlx_d->mlx_ptr, mlx_d->img_ptr);
	mlx_clear_window(mlx_d->mlx_ptr, mlx_d->win_ptr);
	mlx_destroy_window(mlx_d->mlx_ptr, mlx_d->win_ptr);
	exit(0);
	return (0);
}

int	win_esc(int keypress, t_mlx_data *mlx_d)
{
	if (keypress == ESC_KEY)
	{
		mlx_destroy_image(mlx_d->mlx_ptr, mlx_d->img_ptr);
		mlx_clear_window(mlx_d->mlx_ptr, mlx_d->win_ptr);
		mlx_destroy_window(mlx_d->mlx_ptr, mlx_d->win_ptr);
		exit(0);
	}
	return (0);
}

int	zoom(int button, int x, int y, t_mlx_data *mlx_d)
{
	double	ratio_x;
	double	ratio_y;

	x = (int)x;
	y = (int)y;
	ratio_x = (mlx_d->data->zoom_re - mlx_d->data->ori_re) / \
	mlx_d->data->width;
	ratio_y = (mlx_d->data->ori_im - mlx_d->data->zoom_im) / \
	mlx_d->data->height;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		if (button == ZOOM_IN)
			zoom_in(mlx_d->data);
		else if (button == ZOOM_OUT)
			zoom_out(mlx_d->data);
		mlx_d->data->ori_re = mlx_d->data->zoom_re - \
		(ratio_x * mlx_d->data->width);
		mlx_d->data->ori_im = mlx_d->data->zoom_im + \
		(ratio_y * mlx_d->data->height);
		switch_frame(mlx_d);
	}
	return (0);
}
