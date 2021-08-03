/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:17:47 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:40:17 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*alloc(size_t size, size_t len)
{
	char	*alloc;

	alloc = malloc(size * len);
	if (!alloc)
		ft_exit();
	return (alloc);
}

void	ft_exit(void)
{
	int	errno;

	printf("%s\n", strerror(errno));
	exit(errno);
}

void	exit_usage(int error)
{
	if (error == USAGE)
		printf("usage:\n- mandelbrot: ./fractol [-m]\n\
- julia: ./fractol [-j re im]\n");
	if (error == PARAMS)
		printf("julia: invalid parameters:\n\
re and im in range ]-100 ; 100[ with max precision of 1.0E-30,\n\
Examples: [+0.285 +0.01] [-0.8 +0.156] [-0.4 +0.6]\n");
	exit(error);
}
