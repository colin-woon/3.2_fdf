/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:06:53 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/30 16:05:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Duplicate a string.

Returns a pointer to the newly allocated string,
or a null pointer if an error occurred.
The returned pointer must be passed to free to avoid a memory leak.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	if (s == NULL)
	{
		dup = (char *)malloc(sizeof (char));
		dup[0] = '\0';
		return (dup);
	}
	size = (ft_strlen(s) + 1) * sizeof(char);
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, size);
	return (dup);
}
