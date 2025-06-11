/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:31:07 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/16 19:44:18 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		x2;
	int		y;

	y = 10;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y < 40)
	{
		x = 10;
		while (x < 40)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	y = 10;
	x2 = 99;
	while (y < 40)
	{
		x = 100;
		while (x > x2)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x--;
		}
		x2--;
		y++;
	}
	y = 10;
	x2 = 101;
	while (y < 40)
	{
		x = 100;
		while (x < x2)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		x2++;
		y++;
	}
	y = 10;
	x2 = 210;
	while (y < 40)
	{
		x = 200;
		while (x < x2)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		x2++;
		x2++;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
