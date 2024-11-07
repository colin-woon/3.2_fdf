/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:47:19 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 21:12:27 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstdelone -- removes one element from the list
SYNOPSIS
    void ft_lstdelone(t_list *lst, void (*del)(void *));
DESCRIPTION
    Free the memory of the element passed as parameter using the 'del'
	function then free(3). The memory of 'next' must not be freed.
PARAMETERS
    lst: the element to free
    del: address of the function that can delete the element's content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
