/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:56:43 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/10 19:18:36 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//char	ft_transform_char(unsigned int index, char c); //hide 

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
	{
		return (0);
	}
	str = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strmapi("hello world", ft_transform_char));
	return (0);
}

char	ft_transform_char(unsigned int index, char c)
{
	if (index % 2 == 0)
	{
		return (ft_toupper(c));
	}
	else
	{
		return (c);
	}
}*/