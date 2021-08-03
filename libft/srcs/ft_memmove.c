/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:29:33 by fhamel            #+#    #+#             */
/*   Updated: 2019/11/07 13:09:07 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	c_dst = (char *)dst;
	c_src = (char *)src;
	if (!dst || !src)
		return (NULL);
	if (src < dst)
	{
		while (len > 0)
		{
			(c_dst)[len - 1] = (c_src)[len - 1];
			len--;
		}
	}
	else if (c_dst < c_src)
		ft_memcpy(c_dst, c_src, len);
	return (dst);
}
