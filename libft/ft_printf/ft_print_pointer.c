/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:15:01 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 09:27:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

int			print_pointer(va_list args);
static int	hex_conversor(uintptr_t n);
static int	hex_printer(char *str, int len);

int	print_pointer(va_list args)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (hex_conversor(ptr));
}

static int	hex_conversor(uintptr_t n)
{
	int		i;
	int		remainder;
	char	hex_str[32];

	i = 0;
	if (n == 0)
	{
		hex_str[i++] = '0';
		hex_str[i] = '\0';
		return (hex_printer(hex_str, 1));
	}
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder <= 9)
			hex_str[i] = '0' + remainder;
		else if (remainder >= 10)
			hex_str[i] = 'a' + (remainder - 10);
		n = n / 16;
		i++;
	}
	hex_str[i] = '\0';
	return (hex_printer(hex_str, i));
}

static int	hex_printer(char *str, int len)
{
	int	i;

	write (1, "0x", 2);
	i = 0;
	while (len > 0)
	{
		write(1, &str[len - 1], 1);
		len--;
		i++;
	}
	return (i + 2);
}
