/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:33:20 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/17 14:55:17 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t n_elem, size_t el_size);

void	*ft_calloc(size_t n_elem, size_t el_size)
{
	char	*ptr;

	if (el_size != 0 && n_elem > (__SIZE_MAX__ / el_size))
		return (NULL);
	ptr = (char *)malloc(n_elem * el_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, (n_elem * el_size));
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	int	i;
	char	*s;
	printf("%p\n", ft_calloc(10, sizeof(int)));
	printf("%p\n", ft_calloc(10, 0));
	printf("%p\n", ft_calloc(0, sizeof(int)));
	s = ft_calloc(10, sizeof(int));

	i = 0;
	while (i <  10)
	{
		printf("%d",(unsigned char)s[i]);
		i++;
	}
	return (0);
}*/