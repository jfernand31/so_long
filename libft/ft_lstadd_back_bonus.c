/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:59:08 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/17 15:04:39 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;
	t_list	*lst;

	node1 = malloc(sizeof(*node1));
	node2 = malloc(sizeof(*node2));
	node3 = malloc(sizeof(*node3));
	node4 = malloc(sizeof(*node4));
	node5 = malloc(sizeof(*node5));
	lst = malloc(sizeof(*lst));

	node3 = ft_lstnew("!");
	lst->next = node3;
	node2->content = "World";
	node1->content = "Hello";
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);
	node4 = ft_lstnew("!!!!!");
	ft_lstadd_back(&lst, node4);
	printf("%d\n", ft_lstsize(lst));
	int	i = 0;
	node5 = ft_lstlast(lst);
	while (((char *)node5->content)[i] != '\0')
    {
        printf("%c", ((char *)node5->content)[i]);
        i++;
    }
    printf("\n");
	return (0);
}*/
