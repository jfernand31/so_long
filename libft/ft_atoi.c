/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:11:26 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/13 18:32:37 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	result;

	i = 0;
	is_neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			is_neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * is_neg);
}

/*#include <stdio.h>
int	main(void)
{
	printf ("%d\n", ft_atoi("  	-5467ASSADsda"));
	printf ("%d\n", ft_atoi("  	-+5467ASSADsda"));
	printf ("%d\n", ft_atoi("  	-A5467ASSADsda"));
	printf ("%d\n", ft_atoi("?  	-5467ASSADsda"));
	printf ("%d\n", ft_atoi("  	5467ASSADsda"));
	printf ("%d\n", ft_atoi("  	+5467ASSADsda"));
	return (0);
}*/