/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:42:50 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 17:27:32 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data)
{
	data->width /= 3;
	data->height /= 3;
}

void	zoom_out(t_data *data)
{
	data->width *= 3;
	data->height *= 3;
}

void	switch_frame(t_mlx_data *mlx_d)
{
	free_arr_pix(mlx_d);
	if (mlx_d->data->set == MANDELBROT)
		mlx_d->arr_pix = mandelbrot(mlx_d->data);
	else if (mlx_d->data->set == JULIA)
		mlx_d->arr_pix = julia(mlx_d->data);
	mlx_destroy_image(mlx_d->mlx_ptr, mlx_d->img_ptr);
	mlx_d->img_ptr = mlx_new_image(\
	mlx_d->mlx_ptr, mlx_d->data->win_x, mlx_d->data->win_y);
	mlx_d->img_addr = mlx_get_data_addr(\
	mlx_d->img_ptr, &(mlx_d->bpp), &(mlx_d->sl), &(mlx_d->endian));
	fill_img(mlx_d);
	mlx_put_image_to_window(\
	mlx_d->mlx_ptr, mlx_d->win_ptr, mlx_d->img_ptr, 0, 0);
}
