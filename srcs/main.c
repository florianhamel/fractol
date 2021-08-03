/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:21:30 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:00:12 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		exit_usage(USAGE);
	if (ac == 2 && ft_strncmp(av[1], "-m", 3))
		exit_usage(USAGE);
	if (ac == 4 && ft_strncmp(av[1], "-j", 3))
		exit_usage(USAGE);
	if (ac == 4 && (!check_param(av[2]) || !check_param(av[3])))
		exit_usage(PARAMS);
	if (ac == 2)
		start_mandelbrot(ZOOM_AUTO);
	if (ac == 4)
		start_julia(av, ZOOM_AUTO);
	return (0);
}
