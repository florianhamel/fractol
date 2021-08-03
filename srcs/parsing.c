/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:36:39 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:45:07 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_sign(char *p)
{
	int	i;

	i = 0;
	while (p[i] == '0')
	{
		if (p[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

double	get_param(char *p)
{
	int		sign;
	double	param;
	double	precision;
	int		i;

	sign = 1;
	if (p[0] == '-')
		sign = -1;
	param = ft_atoi(p);
	precision = 0;
	i = 0;
	while (p[i] && p[i] != '.')
		i++;
	if (p[i] == '\0')
		return (param);
	i = ft_strlen(p) - 1;
	while (i >= 0 && p[i] != '.')
	{
		precision = (precision * 0.1) + (p[i] - '0');
		i--;
	}
	precision *= 0.1;
	return (sign * (param + precision));
}

int	check_param(char *p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (p[i] == '-' || p[i] == '+')
		i++;
	while (p[i] == '0')
		i++;
	j = i;
	while (p[j] && ft_isdigit(p[j]))
		j++;
	if ((j - i) > 2 || (p[j] != '\0' && p[j] != '.'))
		return (0);
	if (p[j] == '\0')
		return (1);
	if (p[j] == '.')
		j++;
	k = j;
	while (p[k] && ft_isdigit(p[k]))
		k++;
	if ((k - j) > 30 || p[k] != '\0')
		return (0);
	return (1);
}
