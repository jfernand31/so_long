/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:26:56 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/26 17:35:01 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_parser(char *map, t_node **map_lst)
{
	char	*line;
	int		fd;
	int		count;
	t_node	*node;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		node = new_node(line);
		add_to_back(map_lst, node);
		free(line);
	}
	close(fd);
	return (count);
}
