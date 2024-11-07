/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:41 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_strmapi -- apply a function to each character of a string
SYNOPSIS
    char *ft_strmapi(const char *s, char (*f)(unsigned int, char));
DESCRIPTION
    Apply the function 'f' to each characters in the string 's'
	to create a new string (with malloc(3))
	resulting of the successive applications of 'f'.
PARAMETERS
    s: string over which to iterate
    f: function to apply to each character
RETURN VALUES
    ft_strmapi() returns a new string resulting of
	the successive applications of 'f'; NULL if the memory allocations failed.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (s == NULL)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
