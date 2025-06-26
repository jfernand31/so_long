/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:31:07 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/25 19:39:21 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <signal.h>
#include <X11/X.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
    if (keycode == 65307) // Escape key
	{
		close_win(vars);
		exit(0);
	}
	return (0);
}
int key_hook(int keycode, t_vars *vars)
{
    (void)vars;
    ft_printf("Key pressed: %d\n", keycode);
    return (0);
}
int	main(void)
{
	//void	*mlx;
	//void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		color;
	t_vars	vars;

	vars.mlx = mlx_init();
	y = 10;
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	color = create_trgb(0, 0xFF, 0xC0, 0xCB);
	int i = 1;
	while (y < 1000)
	{
		x = 10;
		while (x < 1000)
		{
			my_mlx_pixel_put(&img, x, y, (color));
			x++;
			i++;
		}
		y++;
	
    }
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_loop(vars.mlx);
}
