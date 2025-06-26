/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:50 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/26 19:37:07 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_to_back(t_node **lst, t_node *new_node)
{
	t_node	*temp;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

t_node	*new_node(char *line)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

int	stack_size(t_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	stack_clear(t_node **lst)
{
	t_node	*temp;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->line);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
