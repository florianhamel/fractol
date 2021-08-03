/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:28:26 by fhamel            #+#    #+#             */
/*   Updated: 2019/11/07 13:17:43 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*b_char;
	unsigned char	c_uc;
	size_t			i;

	b_char = (char *)b;
	c_uc = (unsigned char)c;
	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		b_char[i] = c_uc;
		i++;
	}
	return (b);
}
