/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:43:23 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    strncmp -- compare strings
SYNOPSIS
    int strncmp(const char *s1, const char *s2, size_t n);
DESCRIPTION
    The strncmp() function lexicographically compare
	the null-terminated strings s1 and s2.
    The strncmp() function compares not more than n characters.
	Because strncmp() is designed for comparing strings rather than
	binary data, characters that appear after a '\0' character are not compared.
RETURN VALUES
    The strncmp() function returns an integer greater than,
	equal to, or less than 0, according as the string s1 is greater than,
	equal to, or less than the string s2.
	The comparison is done using unsigned characters,
	so that '\200' is greater than '\0'.
1st check	:Source string is not null, reaches to the end
2nd check	:Source string and dest string are the the same,
continues with the checking, if difference is found it will break the loop
3rd check	:n is not decremented to 0, limited comparison
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
