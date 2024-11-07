/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:55:42 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/30 16:03:32 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    strchr -- locate character in string
SYNOPSIS
    char *strchr(const char *s, int c);
DESCRIPTION
    The strchr() function locates the first occurence of
	c (converted to a char) in the string pointed to by s.
	The terminating null character is considered to be part of the string;
	therefor if c is '\0', the function locate the terminating '\0'.
RETURN VALUES
    The function strchr() return a pointer to the located character,
	or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] != (char)c))
	{
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	if (!s[i])
		return (NULL);
	return ((char *)s + i);
}
