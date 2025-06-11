/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:40:33 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/13 17:18:08 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (*little == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && little[j] != '\0' && (big[i + j] == little[j]))
			j++;
		if (little[j] == '\0')
			return (ptr = (char *)&big[i]);
		i++;
	}
	return (ptr = 0);
}

/*#include <stdio.h>
int	main(void)
{
	printf ("%p\n", ft_strnstr("Hello Wor World", "World", 8));
	printf ("%s\n", ft_strnstr("Hello Wor World", "", 0));
	return (0);
}*/