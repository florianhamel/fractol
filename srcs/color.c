/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:49:58 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:09:14 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	convergence_speed_color(t_comp z)
{
	int	color;

	color = 255 - (255 * 127 * modulus(z));
	color = (color << 8) + (255 - (255 * 127 * modulus(z)));
	color = (color << 8) + (255 - (255 * 127 * modulus(z)));
	return (color);
}

int	diverge_speed_color(int iter, int max_iter)
{
	int	color;

	color = 255 - (255 * iter / max_iter);
	color = (color << 8) + (200 - (200 * iter / max_iter));
	color = (color << 8) + (255 - (255 * iter / max_iter));
	return (color);
}

int	rgb_to_int(int red, int green, int blue)
{
	int	color;

	color = red;
	color = (color << 8) + green;
	color = (color << 8) + blue;
	return (color);
}

/*
**colors[0] = rgb_to_int(223, 255, 0);
**colors[1] = rgb_to_int(255, 191, 0);
**colors[2] = rgb_to_int(255, 127, 80);
**colors[3] = rgb_to_int(222, 49, 99);
**colors[4] = rgb_to_int(159, 226, 191);
**colors[5] = rgb_to_int(64, 224, 208);
**colors[6] = rgb_to_int(100, 149, 237);
**colors[7] = rgb_to_int(204, 204, 255);
*/

int	get_divergence_color(int iter, int max_iter)
{
	int	color;

	color = (int)fmax(50, 255 - 255 * iter / max_iter);
	color = (color << 8) + (int)fmax(50, 255 - 255 * iter / max_iter);
	color = (color << 8) + (int)fmax(170, 255 - pow(255 * iter / max_iter, 2));
	return (color);
}

int	get_divergence_color_map(int iter)
{
	int	colors[8];

	colors[0] = 0xC219DA;
	colors[1] = 0xFBE04B;
	colors[2] = 0x2D49D4;
	colors[3] = 0x8EF8A6;
	colors[4] = 0x2D25DB;
	colors[5] = 0xF47A34;
	colors[6] = 0xEB4EB4;
	return (colors[iter % 7]);
}
