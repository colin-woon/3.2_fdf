/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:33:11 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 17:01:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Copies string from one source to another with the option to limit the copy while
safely null-terminating the destination buffer
Input	:Destination pointer `*dest`, source pointer `*src`,
		copy 'index' limit `size`
Output	:Total size of source string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && --size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
