/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:01:31 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_strtrim -- trims character set from string
SYNOPSIS
    char *ft_strtrim(const char *s1, const char *set);
DESCRIPTION
    Allocate (with malloc(3)) and returns a copy of s1,
	without the characters specified in set at the beginning and the end of s1.
PARAMETERS
    s1: string to trim
    set: characters to trim
RETURN VALUES
    ft_strtrim() returns a trimmed copy of s1;
	NULL if the memory allocation failed.
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trimmed_str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		trimmed_str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (trimmed_str == NULL)
			return (NULL);
		else
			ft_strlcpy(trimmed_str, &s1[i], j - i + 1);
	}
	return (trimmed_str);
}
