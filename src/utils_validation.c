/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:56:18 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/26 19:03:37 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_shape(t_node **map)
{
	t_node	*temp;
	int		fst_size;
	int		curr_size;

	temp = *map;
	fst_size = ft_strlen(temp->line);
	temp = temp->next;
	while (temp != NULL)
	{
		curr_size = ft_strlen(temp->line);
		if (curr_size != fst_size)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_collectible(char *line)
{
	int	i;
	int	collectible;

	i = 0;
	collectible = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			collectible++;
		i++;
	}
	return (collectible);
}
