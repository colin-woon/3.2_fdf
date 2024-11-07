/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:27:50 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstmap -- creates a new list resulting
	from the application of f to each element
SYNOPSIS
    t_list *ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *));
DESCRIPTION
    Iterate over the list 'lst' and apply the function 'f'
	to the content of each elements.
	Create a new list resulting of the successive applications of 'f'.
	The function 'del' is used to destroy the content of an element if necessary.
PARAMETERS
    lst: pointer address to one element
    f: the address of the function to apply
    del: the address of the function that can delete an element's content
RETURN VALUES
    New list after successive applications of 'f'
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, (*del));
			break ;
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
