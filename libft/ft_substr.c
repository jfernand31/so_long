/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:04:00 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/26 11:52:15 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_substr("Hello World", 10, 10));
	printf("%s\n", ft_substr("Hello World", 6, 3));
	printf("%s\n", ft_substr("Hello World", 6, 0));
	printf("%s\n", ft_substr("Hello World", 6, 0));
	printf("%s\n", ft_substr("Hello World", 20, 3));
	printf("%s\n", ft_substr("Hello World", 20, 3));
	return (0);
}*/