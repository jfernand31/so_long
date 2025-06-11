/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:49:21 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/11 19:58:00 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//void	my_test_function(unsigned int index, char *c);

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello World";

	ft_striteri(str, my_test_function);
	printf("%s\n", str);
	return (0);
}

void	my_test_function(unsigned int index, char *c)
{
	printf("At index %u, character is '%c'\n", index, *c);
	if (*c >= 'a' && *c <= 'z')
	{
		*c = (*c - 32);
	}
}*/