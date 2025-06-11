/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:01:25 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 08:25:09 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			print_hex(va_list args, unsigned int is_case);
static int	hex_conversor(unsigned int n, unsigned int is_case);
static int	hex_printer(char *str, int len);

int	print_hex(va_list args, unsigned int is_case)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	return (hex_conversor(n, is_case));
}

static int	hex_conversor(unsigned int n, unsigned int is_case)
{
	int		i;
	int		remainder;
	char	hex_str[32];

	i = 0;
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder <= 9)
			hex_str[i] = '0' + remainder;
		else if (remainder >= 10 && is_case == 0)
			hex_str[i] = 'a' + (remainder - 10);
		else if (remainder >= 10 && is_case == 1)
			hex_str[i] = 'A' + (remainder - 10);
		n = n / 16;
		i++;
	}
	return (hex_printer(hex_str, i));
}

static int	hex_printer(char *str, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		write(1, &str[len - 1], 1);
		len--;
		i++;
	}
	return (i);
}
