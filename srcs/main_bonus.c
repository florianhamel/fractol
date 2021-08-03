/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:55:02 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:44:20 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		exit_usage(USAGE);
	if (ac == 2 && !ft_strncmp(av[1], "-m", 3))
		start_mandelbrot_set(ZOOM_MOUSE);
	if (ac == 2 && !ft_strncmp(av[1], "--bonus", 8))
		start_burning_ship(ZOOM_MOUSE);
	if (ac == 2)
		exit_usage(USAGE);
	if (ac == 4 && ft_strncmp(av[1], "-j", 3))
		exit_usage_bonus(USAGE);
	if (ac == 4 && (!check_param(av[2]) || !check_param(av[3])))
		exit_usage(PARAMS);
	if (ac == 4)
		start_julia_set(av, ZOOM_MOUSE);
	return (0);
}
