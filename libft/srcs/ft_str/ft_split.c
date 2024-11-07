/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:39:05 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 17:04:03 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_strings(char *str, char c)
{
	int	i;
	int	no_of_strings;

	i = 0;
	no_of_strings = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			no_of_strings++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (no_of_strings);
}

static	int	ft_strlen_no_sep(char *str, char sep)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0' && str[i] != sep)
		i++;
	return (i);
}

static	char	*assign_word(char *str, char c)
{
	int		i;
	char	*word;
	int		word_len;

	i = 0;
	word_len = ft_strlen_no_sep(str, c);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == 0 || str == 0)
		return (NULL);
	while (i < word_len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
NAME
    ft_split -- split a string into an array of words
SYNOPSIS
    char **ft_split(const char *s, char c);
DESCRIPTION
    Allocate (with malloc(3)) and returns an array of strings obtained
	by splitting s with the character c, used as delimiter.
    The returned array must be NUL-terminated.
PARAMETERS
    s: string to split
    c: delimiter character
RETURN VALUES
    ft_split() returns an array of strings resulting from the splitting of s;
	NULL if the memory allocation failed.
 */
char	**ft_split(const char *s, char c)
{
	char	**strings;
	int		nth_string;

	nth_string = 0;
	strings = (char **)malloc(sizeof(char *) \
			* (count_strings((char *)s, c) + 1));
	if (strings == 0 || s == 0)
		return (NULL);
	while (*s)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			strings[nth_string] = assign_word((char *)s, c);
			nth_string++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	strings[nth_string] = 0;
	return (strings);
}
