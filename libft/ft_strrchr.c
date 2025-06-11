/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:35:00 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/14 16:33:51 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			ptr = ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	char	*str = "Hello \0World";

	char *ret = ft_strrchr(str, 1024 + 'e');
	printf ("%p\n", ret);
	return (0);
}*/