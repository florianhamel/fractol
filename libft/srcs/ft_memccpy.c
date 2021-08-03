/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:58:56 by fhamel            #+#    #+#             */
/*   Updated: 2019/10/22 15:36:35 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;
	unsigned char	c_uc;
	size_t			i;

	if (!dst || !src)
		return (NULL);
	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	c_uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst_uc[i] = src_uc[i];
		if (src_uc[i] == c_uc)
			return (&dst_uc[i + 1]);
		i++;
	}
	return (NULL);
}
