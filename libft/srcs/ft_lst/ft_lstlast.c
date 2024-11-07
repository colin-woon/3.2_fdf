/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:32:12 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/03 17:41:43 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstlast -- get the last node of the list
SYNOPSIS
    t_list *ft_lstlast(t_list *lst);
DESCRIPTION
    Returns the last node of the list
PARAMETERS
    lst: the start of the list
RETURN VALUES
    Last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
