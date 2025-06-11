/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:58:24 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/23 15:03:49 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int			ft_printf(const char *format, ...);
static int	handle_format(const char *format, va_list args);
static int	dispatch(char specifier, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;

	va_start(args, format);
	total_len = handle_format(format, args);
	va_end(args);
	return (total_len);
}

static int	handle_format(const char *format, va_list args)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total += dispatch(format[i], args);
		}
		else
			total += write(1, &format[i], 1);
		i++;
	}
	return (total);
}

static int	dispatch(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(args));
	if (specifier == 's')
		return (print_str(args));
	if (specifier == 'p')
		return (print_pointer(args));
	if (specifier == 'd' || specifier == 'i')
		return (print_int(args));
	if (specifier == 'u')
		return (print_unsigned(args));
	if (specifier == 'x')
		return (print_hex(args, 0));
	if (specifier == 'X')
		return (print_hex(args, 1));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

/*#include <stdio.h>

int main(void)
{
    // Test 1: Basic String Print
    ft_printf("Test 1: Basic String Print\n");
    ft_printf("Hello, World!\n\n");

    // Test 2: Print a Character
    ft_printf("Test 2: Print a Character\n");
    ft_printf("Character: %c\n\n", 'A');

    // Test 3: Print a String
    ft_printf("Test 3: Print a String\n");
    ft_printf("String: %s\n\n", "Hello, printf!");

    // Test 4: Print a Pointer
    ft_printf("Test 4: Print a Pointer\n");
    int num = 42;
    ft_printf("Pointer: %p\n\n", &num);

    // Test 5: Print an Integer (Decimal)
    ft_printf("Test 5: Print an Integer (Decimal)\n");
    ft_printf("Integer: %d\n\n", 12345);

    // Test 6: Print a Negative Integer
    ft_printf("Test 6: Print a Negative Integer\n");
    ft_printf("Negative Integer: %d\n\n", -12345);

    // Test 7: Print an Unsigned Integer
    ft_printf("Test 7: Print an Unsigned Integer\n");
    ft_printf("Unsigned Integer: %u\n\n", 12345);

    // Test 8: Print Hexadecimal (Lowercase)
    ft_printf("Test 8: Print Hexadecimal (Lowercase)\n");
    ft_printf("Hexadecimal (lowercase): %x\n\n", 255);

    // Test 9: Print Hexadecimal (Uppercase)
    ft_printf("Test 9: Print Hexadecimal (Uppercase)\n");
    ft_printf("Hexadecimal (uppercase): %X\n\n", 255);

    // Test 10: Print Percentage Sign
    ft_printf("Test 10: Print Percentage Sign\n");
    ft_printf("Percentage: %%\n\n");

    // Test 11: Multiple Specifiers
    ft_printf("Test 11: Multiple Specifiers\n");
    ft_printf("Multiple: %c %d %x %p\n\n", 'B', 42, 42, &num);

    // Test 12: Edge Case with Empty String
    ft_printf("Test 12: Edge Case with Empty String\n");
    ft_printf("");  // Expected: (nothing printed)
    ft_printf("\n");

    // Test 13: Print Zero for Pointer (Null Pointer)
    ft_printf("Test 13: Print Zero for Pointer\n");
    ft_printf("Null Pointer: %p\n\n", NULL);

    // Test 14: Edge Case with No Format Specifier
    ft_printf("Test 14: Edge Case with No Format Specifier\n");
    ft_printf("Just text with no specifiers.\n\n");

    // Test 15: Very Large Numbers (Edge Case)
    ft_printf("Test 15: Very Large Numbers\n");
    ft_printf("Large Number: %d\n", 2147483647);  
    ft_printf("Large Number (unsigned): %u\n", -42);  

	// Test 16: Print Zero for Pointer (Null Pointer)
    ft_printf("Test 13: Print Zero for Pointer\n");
    ft_printf("Null Pointer: %p %p\n\n", NULL, NULL);

	// Test 17: Print Zero for Pointer (Null Pointer)
    ft_printf("Test 13: Print Zero for Pointer\n");
    ft_printf("Null Pointer: %p %p\n\n", 0, 0);
    return 0;
}*/
