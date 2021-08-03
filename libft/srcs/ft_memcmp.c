/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:29:16 by fhamel            #+#    #+#             */
/*   Updated: 2019/11/07 13:46:17 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;
	unsigned char	i;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (s1 && !s2)
		return (*s1_uc);
	if (!s1 && s2)
		return (*s2_uc);
	i = 0;
	while (i < (n - 1) && s1_uc[i] == s2_uc[i])
		i++;
	return (s1_uc[i] - s2_uc[i]);
}
