/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:04 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/15 19:21:20 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstsize(lst->next));
}
/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*lst;

	node1 = malloc(sizeof(*node1));
	node2 = malloc(sizeof(*node2));
	node3 = malloc(sizeof(*node3));
	lst = malloc(sizeof(*lst));

	node3 = ft_lstnew("!");
	lst->next = node3;
	node2->content = "World";
	node1->content = "Hello";
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);

	printf("%d\n", ft_lstsize(lst));
	return (0);
}*/