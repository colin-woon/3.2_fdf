/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:25:59 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    calloc -- memory allocation
SYNOPSIS
    void *calloc(size_t count, size_t size);
DESCRIPTION
    The calloc() function allocates memory.
    The allocated memory is aligned such that it can be used for any data type.
    The calloc() function contigously allocates enough space for `count` objects
	that are `size` bytes of memory each and
	returns a pointer to the allocated memory.
    The allocated memory is filled with bytes of value zero.
	The difference with malloc() is that calloc() sets all the memory bytes to 0
	instead of staying as ??? in memory before we allocated it.
RETURN VALUES
    If successful, calloc() returns a pointer to allocated memory.
	If there is an error, they return a NULL pointer and set errno to ENOMEM.
 */

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*memory_holder;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	memory_holder = (void *)malloc(count * size);
	if (memory_holder == NULL)
		return (NULL);
	ft_bzero(memory_holder, (count * size));
	return (memory_holder);
}
