/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:02:37 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Locates the last specified character in a string, reverse, hence strrchr
Input	:String `*str`, character to find `i` (integer promotion applied)
Output	:Returns the pointer pointing to where the character is found

NAME
    strrchr -- locate character in string
SYNOPSIS
    char *strrchr(const char *s, int c);
DESCRIPTION
    The strrchr() function is identical to strchr(),
	except it locates the last occurence of c.
RETURN VALUES
    The function strrchr() returns a pointer to the located character,
	or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*last_char;
	char			cc;

	cc = (char) c;
	last_char = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			last_char = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		last_char = (char *) &s[i];
	return (last_char);
}
