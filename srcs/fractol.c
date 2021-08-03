/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:34:36 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:08:27 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_data(int set, int zoom_mode)
{
	t_data	*data;

	data = alloc(sizeof(t_data), 1);
	data->win_y = 576;
	data->win_x = 768;
	data->ori_re = -2;
	data->ori_im = 1.5;
	data->width = 4;
	data->height = 3;
	data->set = set;
	data->zoom_mode = zoom_mode;
	data->zoom_re = 0;
	data->zoom_im = 0;
	data->color = CHILL;
	data->c = (t_comp){.re = 0, .im = 0};
	return (data);
}

// t_data	*init_data(int set, int zoom_mode)
// {
// 	t_data	*data;

// 	data = alloc(sizeof(t_data), 1);
// 	data->win_y = 768;
// 	data->win_x = 1024;
// 	data->center_im = 0;
// 	data->center_re = 0;
// 	data->height = 1.5;
// 	data->width = 2;
// 	data->zoom_pow = 0;
// 	data->zoom = 2;
// 	data->zoom_mode = zoom_mode;
// 	data->set = set;
// 	data->c = (t_comp){.re = 0, .im = 0};
// 	return (data);
// }

int	**init_arr_pix(t_data *data)
{
	int	**arr_pix;
	int	y;

	y = 0;
	arr_pix = alloc(sizeof(int *), data->win_y);
	while (y < data->win_y)
	{
		arr_pix[y] = alloc(sizeof(int), data->win_x);
		y++;
	}
	return (arr_pix);
}
