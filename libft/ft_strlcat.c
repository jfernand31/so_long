/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:44:19 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/11 20:18:17 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (i < size - dest_len)
	{
		dest[dest_len + i] = '\0';
	}
	if (size < dest_len)
		return (src_len + size);
	else
		return (dest_len + src_len);
}

/*#include <stdio.h>
int	main(void)
{
	char dest[7] = "Hello";
	char src[7] = " World";

	printf ("%s\n", dest);
	printf ("%zu\n", ft_strlcat(dest, src, 12));
	printf ("%s\n", dest);
	return (0);
}*/