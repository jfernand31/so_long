/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:36:32 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/11 19:15:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
	{
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	int i;
	char src[12] = "Hello World";
	char dest[12];

	ft_memcpy(dest, src, 12);

	i = 0;
	while (i < 12)
	{
		printf("%c ", dest[i]);
		printf("%c ", src[i]);
		i++;
	}
	return (0);
}*/