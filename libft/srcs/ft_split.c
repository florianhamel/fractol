/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:52:53 by fhamel            #+#    #+#             */
/*   Updated: 2021/07/10 19:08:28 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_words(char const *s, char c)
{
	int	nb_words;
	int	i;

	nb_words = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		nb_words++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_words);
}

int	len_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	free_arr(char **arr, int nb_words)
{
	int	i;

	i = 0;
	while (i < nb_words)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

char	**arr_alloc(const char *s, char c)
{
	char	**arr;
	int		index;
	int		i;

	arr = ft_malloc(sizeof(char *), nb_words(s, c) + 1);
	if (!arr)
		return (NULL);
	index = 0;
	i = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		arr[i] = (char *)ft_calloc(len_word(&s[index], c) + 1, sizeof(char));
		if (!arr[i])
		{
			free_arr(arr, i);
			return (NULL);
		}
		index += len_word(&s[index], c);
		i++;
	}
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		index;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	arr = arr_alloc(s, c);
	if (!arr)
		return (NULL);
	index = 0;
	i = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (!s[index])
			break ;
		j = 0;
		while (s[index] && s[index] != c)
			arr[i][j++] = s[index++];
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
