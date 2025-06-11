/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:02:09 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 08:25:11 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			print_int(va_list args);
static int	ft_putnbr(int n);

int	print_int(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (ft_putnbr(n));
}

static int	ft_putnbr(int n)
{
	char	c;
	int		total_len;

	total_len = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		total_len += 1;
		n = -n;
	}
	if (n > 9)
		total_len += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
	return (total_len + 1);
}
