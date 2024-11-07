/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:04:27 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 21:12:16 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstclear -- removes the element passed as parameter and
	all the following elements
SYNOPSIS
    void ft_lstclear(t_list **lst, void (*del)(void *));
DESCRIPTION
    Deletes and free the memory of the element passed as parameter and
	all the following elements using 'del' and free(3).
	Finally, the initial pointer must be set to NULL.
PARAMETERS
    lst: pointer address to one element
    del: address of the function that can delete the element's content
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
	*lst = NULL;
}
