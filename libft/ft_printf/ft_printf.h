/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:55:32 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 08:33:47 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	print_char(va_list args);
int	print_str(va_list args);
int	print_int(va_list args);
int	print_hex(va_list args, unsigned int is_case);
int	print_unsigned(va_list args);
int	print_pointer(va_list args);
int	ft_printf(const char *format, ...);

#endif
