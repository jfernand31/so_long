/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:08:15 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/14 19:05:38 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char		*ft_strtrim(char const *s1, char const *set);
static int	ft_strstart(const char *s1, const char *set);
static int	ft_strend(const char *s1, const char *set, size_t start);
static int	is_in_set(char c, const char *set);

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_strstart(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	return (start);
}

static int	ft_strend(const char *s1, const char *set, size_t start)
{
	size_t	end;

	end = 0;
	while (s1[end])
		end++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = ft_strstart(s1, set);
	end = ft_strend(s1, set, start);
	ptr = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ptr[i] = s1[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%p\n", ft_strtrim("-- Hello -- World --", "-.;"));
	printf("%s\n", ft_strtrim("Bonjour", "s"));
	return (0);
}*/
