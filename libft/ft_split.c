/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:28:42 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/14 19:20:52 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_split(char const *s, char c);
static size_t	count_words(const char *s, char c);
static char		*malloc_word(const char *s, size_t start, size_t end);
static char		**free_all(char **res, size_t i);
static char		**split_words(char **res, const char *s, char c);

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*malloc_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_all(char **res, size_t i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
	return (NULL);
}

static char	**split_words(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = malloc_word(s, start, i);
			if (!res[j])
				return (free_all(res, j));
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = (char **)malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (split_words(res, s, c));
}
