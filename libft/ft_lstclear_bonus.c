/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:33:00 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/19 07:37:31 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		ft_lstdelone(temp, del);
		temp = next;
	}
	*lst = NULL;
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
	ft_lstclear(&lst, del_cont);
	return 0;
}*/