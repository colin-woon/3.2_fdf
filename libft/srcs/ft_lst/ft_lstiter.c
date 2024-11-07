/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:22:27 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_lstiter -- apply a function to each element's content
SYNOPSIS
    void ft_lstiter(t_list *lst, void (*f)(void *));
DESCRIPTION
    Iterate over the list 'lst' and
	apply the function 'f' to the content of all elements.
PARAMETERS
    lst: pointer address to one element
    f: function to apply
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (lst == NULL)
		return ;
	node = lst;
	while (node != NULL)
	{
		(*f)(node->content);
		node = node->next;
	}
}
