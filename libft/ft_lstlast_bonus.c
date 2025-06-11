/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:40:40 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/15 16:58:43 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*lst;
	t_list	*node4;
	int	i = 0;

	node1 = malloc(sizeof(*node1));
	node2 = malloc(sizeof(*node2));
	node3 = malloc(sizeof(*node3));
	node4 = malloc(sizeof(*node4));
	lst = malloc(sizeof(*lst));

	node3 = ft_lstnew("hahahahah");
	lst->next = node3;
	node2->content = "World";
	node1->content = "Hello";
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);

	node4 = ft_lstlast(lst);
	while (((char *)node4->content)[i] != '\0')
    {
        printf("%c", ((char *)node4->content)[i]);
        i++;
    }
    printf("\n");

	return (0);
}*/