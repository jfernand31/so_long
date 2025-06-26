/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:15:34 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/26 19:38:49 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_node	*map_lst;
	int		line_count;
	
	if (argc < 2)
	{
		ft_printf("Usage: ./so_long <map.ber>\n");
		return (1);
	}
	map_lst = NULL;
	line_count = map_parser(argv[1], &map_lst);
	if (!is_map_valid(&map_lst, line_count))
	{
		ft_printf("Invalid Map");
		return (1);
	}
	return (0);
}
