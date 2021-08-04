/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:21:30 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 20:57:06 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac > 1 && !ft_strncmp(av[1], "-m", 3))
		start_mandelbrot(ZOOM_AUTO);
	else if (ac > 3 && !ft_strncmp(av[1], "-j", 3) && \
	check_param(av[2]) && check_param(av[3]))
		start_julia(av, ZOOM_AUTO);
	else if (ac > 3 && !ft_strncmp(av[1], "-j", 3) && \
	(!check_param(av[2]) || !check_param(av[3])))
		exit_usage(PARAMS);
	else
		exit_usage(USAGE);
	return (0);
}
