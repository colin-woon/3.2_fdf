/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:34:30 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/03 12:08:40 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstnew -- create a new list node
SYNOPSIS
    t_list *ft_lstnew(void *content);
DESCRIPTION
    Allocate (with malloc(3)) and return the new node.
	The member variable 'content' is initialized with the value of the
	'content' parameter. The 'next' variable is initialized to NULL.
PARAMETERS
    content: The content of the new node
RETURN VALUES
    The new node.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
