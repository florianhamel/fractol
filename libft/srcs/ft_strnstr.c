/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:47 by fhamel            #+#    #+#             */
/*   Updated: 2021/07/06 14:15:40 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_needle(size_t i, size_t n, const char *hay, const char *needle)
{
	size_t	j;

	j = 0;
	while (hay[i] == needle[j] && needle[j] && i < n)
	{
		i++;
		j++;
	}
	if (!(needle[j]))
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (!haystack && !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	if (needle[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		if (is_needle(i, n, haystack, needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
