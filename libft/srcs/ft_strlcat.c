/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:47:22 by fhamel            #+#    #+#             */
/*   Updated: 2019/10/22 15:37:05 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	output;
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (0);
	if (dstsize < ft_strlen(dst))
		output = ft_strlen(src) + dstsize;
	else
		output = ft_strlen(src) + ft_strlen(dst);
	if (dstsize > 0 && dstsize - 1 > ft_strlen(dst))
	{
		i = 0;
		while (dst[i] != '\0')
			i++;
		j = 0;
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	return (output);
}
