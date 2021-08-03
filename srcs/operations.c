/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:49:33 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:00:23 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** next element of the recurrent sequence zn = zn-1ˆ2 + c
*/
t_comp	z_next(t_comp z, t_comp c)
{
	t_comp	z_next;

	z_next.re = powl(z.re, 2) - powl(z.im, 2);
	z_next.im = 2 * z.re * z.im;
	z_next.re += c.re;
	z_next.im += c.im;
	return (z_next);
}

/*
** let z be a complexe of the form z = a + bi
** |z| = sqrt(aˆ2 + bˆ2)
*/
double	modulus(t_comp z)
{
	double	modulus;

	modulus = sqrtl((powl(z.re, 2) + powl(z.im, 2)));
	return (modulus);
}

/*
** get the coord a of the pixel
** (z = a + bi)
*/
double	get_re_part(int x, t_data *data)
{
	double	offset;
	double	re;

	offset = (double)x / (double)data->win_x * data->width;
	re = data->ori_re + offset;
	return (re);
}

/*
** get the coord b of the pixel
** (z = a + bi)
*/
double	get_im_part(int y, t_data *data)
{
	double	offset;
	double	im;

	offset = (double)y / (double)data->win_y * data->height;
	im = data->ori_im - offset;
	return (im);
}
