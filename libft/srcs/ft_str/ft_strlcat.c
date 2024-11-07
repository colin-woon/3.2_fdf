/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:10:06 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Concatenate strings together while safely null terminating the result.
Input	: Destination string `*dest`, source string `*src`,
		number of concatenation `size`
Output	: Length of source string + index of dest string depending on size
Check obsidian notes
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	dest_len;
	size_t	total_len;
	size_t	i;

	if (dest_size == 0 && (dest == 0 || src == 0))
		return (0);
	dest_len = ft_strlen(dest);
	if (dest_size <= dest_len)
		return (dest_size + ft_strlen(src));
	else
		total_len = dest_len + ft_strlen(src);
	i = 0;
	while (src[i] && dest_len < dest_size - 1)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}
