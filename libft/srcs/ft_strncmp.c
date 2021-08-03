/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:33 by fhamel            #+#    #+#             */
/*   Updated: 2019/11/07 14:39:12 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;
	size_t			i;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (s1 && !s2)
		return (*s1);
	if (!s1 && s2)
		return (*s2);
	i = 0;
	while (i < n - 1 && s1_uc[i] && s2_uc[i] && s1_uc[i] == s2_uc[i])
		i++;
	return (s1_uc[i] - s2_uc[i]);
}
