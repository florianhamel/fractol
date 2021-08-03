/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:59:12 by fhamel            #+#    #+#             */
/*   Updated: 2019/10/22 15:36:36 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uc;
	unsigned char	c_uc;
	size_t			i;

	if (!s)
		return (NULL);
	s_uc = (unsigned char *)s;
	c_uc = (unsigned char)c;
	if (c_uc == 0 && n > ft_strlen((char *)s_uc))
		return (&s_uc[ft_strlen((char *)s_uc)]);
	i = 0;
	while (i < n)
	{
		if (s_uc[i] == c_uc)
			return (&s_uc[i]);
		i++;
	}
	return (NULL);
}
