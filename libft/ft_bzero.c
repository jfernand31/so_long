/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:12:58 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/11 19:15:41 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

/*#include <stdio.h>
int	main(void)
{
	char s[10] = "lololololo";
	int i;

	ft_bzero(s, 8);
	i = 0;
	while (i < 10)
	{
		printf("%c", s[i]);
		i++;
	}
	return (0);
}*/
