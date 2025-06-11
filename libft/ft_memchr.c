/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:56:07 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/14 16:39:51 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return (ptr = (unsigned char *)&s[i]);
		}
		i++;
	}
	return (ptr = 0);
}

/*#include <stdio.h>
int	main(void)
{
	char	*s = "Hello World";

	printf ("%p\n", ft_memchr(s, 'o', 4));
	return (0);
}*/