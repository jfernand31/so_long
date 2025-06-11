/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:01:33 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 08:28:54 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			print_unsigned(va_list args);
static int	ft_putnbr(unsigned int n);

int	print_unsigned(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr(n));
}

static int	ft_putnbr(unsigned int n)
{
	char	c;
	int		total_len;

	total_len = 0;
	if (n > 9)
		total_len += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
	return (total_len + 1);
}
