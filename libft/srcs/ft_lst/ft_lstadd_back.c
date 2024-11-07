/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:37:20 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/03 17:41:02 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstadd_back -- adds a new node at the end of the list
SYNOPSIS
    void ft_lstadd_back(t_list **lst, t_list *new);
DESCRIPTION
    Add the 'new' node at the end of the list
PARAMETERS
    lst: pointer address of the first node of the list
    new: pointer address of the new node to add to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		new->prev = tmp;
	}
}
