/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:55:02 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 20:57:09 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	if (ac > 1 && !ft_strncmp(av[1], "-m", 3))
		start_mandelbrot_set(ZOOM_MOUSE);
	else if (ac > 1 && !ft_strncmp(av[1], "--bonus", 8))
		start_burning_ship(ZOOM_MOUSE);
	else if (ac > 3 && !ft_strncmp(av[1], "-j", 3) && \
	check_param(av[2]) && check_param(av[3]))
		start_julia_set(av, ZOOM_MOUSE);
	else if (ac > 3 && !ft_strncmp(av[1], "-j", 3) && \
	(!check_param(av[2]) || !check_param(av[3])))
		exit_usage_bonus(PARAMS);
	else
		exit_usage_bonus(USAGE);
	return (0);
}
