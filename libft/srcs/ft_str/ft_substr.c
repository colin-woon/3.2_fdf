/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:26:08 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 15:19:13 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_substr -- extract a substring from a string
SYNOPSIS
    char *ft_substr(const char *s, unsigned int start, size_t len);
DESCRIPTION
    Allocate (with malloc(3)) and return a new string from the string s.
    This new string starts at index 'start' and has a maximum size of 'len'.
PARAMETERS
    s: string from which to extract the new string
    start: start index of the new string in the string 's'
    len: maximum size of the new string
RETURN VALUES
    ft_substr() returns the new string; NULL if the memory allocation failed.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
