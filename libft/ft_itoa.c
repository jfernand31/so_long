/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:12:34 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/11 19:48:46 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stddef.h"
#include <stdlib.h>

char			*ft_itoa(int n);
static size_t	ft_intlen(int n);
static char		*ft_getnbr(char *str, int n, size_t len, int is_negative);

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_getnbr(char *str, int n, size_t len, int is_negative)
{
	size_t	i;
	long	digit;

	i = len - 1;
	if (n == 0)
	{
		str[i] = '0';
	}
	while (n != 0)
	{
		digit = n % 10;
		if (digit < 0)
		{
			digit = -digit;
		}
		str[i] = digit + '0';
		i--;
		n = n / 10;
	}
	if (is_negative)
	{
		str[i] = '-';
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
	}
	len = ft_intlen(n);
	str = (char *) malloc ((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	str = ft_getnbr(str, n, len, is_negative);
	return (str);
}

/*#include <stdio.h> // remove this
int	main(void)
{
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(250));
	printf("%d\n", -21 % 10);
	return (0);
}*/