/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:41:20 by jfernand          #+#    #+#             */
/*   Updated: 2025/04/15 19:21:19 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content);

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*#include <stdio.h>
int main(void)
{
    char    str[] = "Hello World";
    int i;
    t_list  *node;

    i = 0;
    node = ft_lstnew(str);
    while (((char *)node->content)[i] != '\0')
    {
        printf("%c", ((char *)node->content)[i]);
        i++;
    }
    printf("\n");
    return (0);
}*/
