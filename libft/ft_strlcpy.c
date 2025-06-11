/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:06:55 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/13 17:07:49 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (size == 0)
	{
		return (srcsize);
	}
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (srcsize);
}

/*#include <stdio.h>
int	main(void)
{
	char dest[12];
	char src[12] = "Hello World";

	printf("%d\n",ft_strlcpy(dest, src, 13));
	printf ("%s\n", dest);
	return (0);
}*/