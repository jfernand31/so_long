/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:50:26 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/11 19:57:25 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/*int main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(42, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(-42, 1);
	write (1, "\n", 1);
	return (0);
}*/