/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:47:17 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/08 18:48:19 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (n == 0)
	{
		return (s);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*#include <stdio.h>
int	main(void)
{
	char	s[10];
	ft_memset(s, 1, 8);
	int i;

	i = 0;
	while (i <  10)
	{
		printf("%d",(unsigned char)s[i]);
		i++;
	}
	return (0);
}*/