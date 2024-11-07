/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:42:16 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Copies a memory block from a source address to a destination address.
Input	:destination memory block pointer `*dest`, source memory block `*src`,
		number of bytes to be copied `n`.
Output	:original destination address `dest`
Usage	:memcpy(dest, src, strlen(src) + 1), includes null terminator
First IF checks for null pointers, Second IF checks for same memory address.
Source Block: [0, 1, 2, 0]
Dest Block: [1, 0, 0, 0]
Result Destination Block: [0, 1, 2, 0]
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
