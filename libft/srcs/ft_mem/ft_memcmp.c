/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:31:31 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    memcmp -- compare byte string
SYNOPSIS
    int memcmp(const void *s1, const void *s2, size_t n)
DESCRIPTION
    The memcmp() function compares byte string s1 against byte string s2.
    Both strings are assumed to be n bytes long.
RETURN VALUES
    The memcmp() function returns zero if the two strings are identical,
	otherwise returns the difference betwee the first two differing bytes
	(treated as unsigned char values,
	so that '\200' is greater than '\0', for example).
    Zero-length strings are always identical.
	This behaviour is not required by C
	and portable code should only depend on the sign of the returned value.

Compares the first num bytes of the block of memory pointed by `s1` to the
first num bytes pointed by `s2`, returning zero if they all match or a value
different from zero representing which is greater if they do not.
Unlike strcmp, the function does not stop comparing after finding a
null character.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
