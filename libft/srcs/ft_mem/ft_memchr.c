/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:43:09 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    memchr -- locate byte in byte string
SYNOPSIS
    void *memchr(const void *s, int c, size_t n);
DESCRIPTION
    the memchr() function locates the first occurence of c
	(convered to an unsigned char) in string s.
RETURN VALUES
    The memchr() function returns a pointer to the byte located,
	or NULL if no such byte exists within n bytes.

Locates a specified character in a string with a limited search option
Input	:String `*src`, character to find `c` (integer promotion applied),
		range of comparison `n`
Output	:Returns the pointer pointing to where the character is found
 */
void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)src;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
