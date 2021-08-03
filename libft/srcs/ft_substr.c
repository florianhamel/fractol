/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:45:27 by fhamel            #+#    #+#             */
/*   Updated: 2021/07/06 14:30:06 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = ft_malloc(sizeof(char), 1);
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	substr = ft_strdup(&s[start]);
	if (!substr)
		return (NULL);
	if (len < ft_strlen(substr))
		substr[len] = '\0';
	return (substr);
}
