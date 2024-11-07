/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:43:05 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 17:04:08 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    strnstr -- locate a substring in a string
SYNOPSIS
    char *strnstr(const char *str, const char *substr, size_t len);
DESCRIPTION
    The strnstr() function locates the first occurence of the null-terminated
	string substr in the string str,
	where not more than len characters are searched.
    Characters that appear after a '\0' character are not searched.
RETURN VALUES
    If substr is an empty string, str is returned;
	if substr occurs nowhere in str, NULL is returned;
	otherwise a pointer to the first character of
	the first occurence of substr is returned.
 */
char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && str == 0)
		return (NULL);
	i = 0;
	if (substr[0] == 0)
		return ((char *) str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == substr[j] && str[i + j] && i + j < len)
		{
			j++;
			if (substr[j] == 0)
				return ((char *) str + i);
		}
		i++;
	}
	return (0);
}
