/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:52:32 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:00:03 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx_data	*init_mlx_data(t_data *data)
{
	t_mlx_data	*mlx_d;

	mlx_d = alloc(sizeof(t_mlx_data), 1);
	mlx_d->data = data;
	mlx_d->mlx_ptr = mlx_init();
	mlx_d->win_ptr = mlx_new_window(mlx_d->mlx_ptr, data->win_x, \
	data->win_y, "Fractol");
	mlx_d->img_ptr = mlx_new_image(mlx_d->mlx_ptr, data->win_x, data->win_y);
	mlx_d->img_addr = mlx_get_data_addr(mlx_d->img_ptr, &(mlx_d->bpp), \
	&(mlx_d->sl), &(mlx_d->endian));
	return (mlx_d);
}

void	free_arr_pix(t_mlx_data *mlx_d)
{
	int	y;

	y = 0;
	while (y < mlx_d->data->win_y)
	{
		free((mlx_d->arr_pix)[y]);
		y++;
	}
	free(mlx_d->arr_pix);
}

void	put_pixel(t_mlx_data *mlx_d, int y, int x)
{
	char	*to_write_addr;

	to_write_addr = (mlx_d->img_addr + \
	(y * mlx_d->sl)) + \
	(x * (mlx_d->bpp / 8));
	*(int *)to_write_addr = mlx_d->arr_pix[y][x];
}

void	fill_img(t_mlx_data *mlx_d)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx_d->data->win_y)
	{
		x = 0;
		while (x < mlx_d->data->win_x)
		{
			put_pixel(mlx_d, y, x);
			x++;
		}
		y++;
	}
}
