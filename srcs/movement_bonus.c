/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:51:56 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:32:11 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move_left(t_mlx_data *mlx_d)
{
	double	offset;

	offset = 0.35 * mlx_d->data->width;
	mlx_d->data->ori_re -= offset;
	switch_frame_set(mlx_d);
}

void	move_up(t_mlx_data *mlx_d)
{
	double	offset;

	offset = 0.35 * mlx_d->data->height;
	mlx_d->data->ori_im -= offset;
	switch_frame_set(mlx_d);
}

void	move_right(t_mlx_data *mlx_d)
{
	double	offset;

	offset = 0.35 * mlx_d->data->width;
	mlx_d->data->ori_re += offset;
	switch_frame_set(mlx_d);
}

void	move_down(t_mlx_data *mlx_d)
{
	double	offset;

	offset = 0.35 * mlx_d->data->height;
	mlx_d->data->ori_im += offset;
	switch_frame_set(mlx_d);
}
