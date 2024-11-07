/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:01:51 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Same as memcopy, but can also overlap existing memory block safely
Input	: destination generic pointer `*dest`, source generic pointer `*src`
		number of bytes to copy `n`
Output	: Returns original address of destination pointer `dest`
Example	: 123456
1st check replaces the values backwards, while 2nd check replaces the values
forward, refer to obsidian notes
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;

	if (dest == NULL && src == NULL)
		return (NULL);
	len = 0;
	if (src < dest)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (len < n)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dest);
}
