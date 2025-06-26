/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:40:46 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/26 18:55:54 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_outer_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

static int	check_player(char *line)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			player++;
		i++;
	}
	return (player);
}

static int	check_exit(char *line)
{
	int	i;
	int	exits;

	i = 0;
	exits = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			exits++;
		i++;
	}
	return (exits);
}

static int	check_valid_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P' || line[i] == 'E' || line[i] == '1'
			|| line[i] == '0' || line[i] == 'C')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_map_valid(t_node **map, int line_count)
{
	t_node		*temp;
	t_counts	c;
	int			i;

	c.player = 0;
	c.exit = 0;
	c.collectible = 0;
	i = 1;
	temp = *map;
	while (temp != NULL)
	{
		if (i == 1 || i == line_count)
			if (!check_outer_wall(temp->line))
				return (0);
		c.player += check_player(temp->line);
		c.exit += check_exit(temp->line);
		c.collectible += check_collectible(temp->line);
		if (!check_valid_chars(temp->line))
			return (0);
		i++;
		temp = temp->next;
	}
	if (c.player != 1 || c.exit != 1 || c.collectible < 1 || !check_shape(map))
		return (0);
	return (1);
}
