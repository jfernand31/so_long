/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:53:37 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/08 19:21:07 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	printf ("%p\n", ft_strdup("Hello World"));
	printf ("%s\n", ft_strdup("Hello World"));
	return (0);
}*/