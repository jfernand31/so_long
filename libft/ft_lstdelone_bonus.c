/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:44:00 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 07:37:34 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
	{
		return ;
	}
	if (del)
	{
		del(lst->content);
	}
	free(lst);
}

/*#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	del_cont(void *ptr)
{
	// Content is a string literal, so don't free it
	(void)ptr;
}

int	main(void)
{
	t_list	*lst;
	t_list	*node1 = ft_lstnew("Hello");
	t_list	*node2 = ft_lstnew("World");
	t_list	*node3 = ft_lstnew("!");
	t_list	*node4 = ft_lstnew("!!!!!");

	// Build the list
	lst = NULL;
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	ft_lstadd_back(&lst, node4);

	printf("List size before deletion: %d\n", ft_lstsize(lst));

	// Get the last node before deletion
	t_list *last = ft_lstlast(lst);
	if (last && last->content)
		printf("Last node content before deletion: %s\n", (char *)last->content);

	// Now: safely unlink node4 from the list
	t_list *prev = lst;
	while (prev && prev->next != node4)
		prev = prev->next;
	if (prev)
		prev->next = NULL; // Unlink node4

	// Now safely delete node4
	ft_lstdelone(node4, del_cont);

	// Get the new last node
	last = ft_lstlast(lst);
	if (last && last->content)
		printf("Last node content after deletion: %s\n", (char *)last->content);

	printf("List size after deletion: %d\n", ft_lstsize(lst));

	return 0;
}*/
