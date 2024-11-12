/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:39:45 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/12 19:39:09 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_striteri -- apply a function to each character of a string
	(index specified)
SYNOPSIS
    void ft_striteri(char *s, void (*f)(unsigned int, char*));
DESCRIPTION
    Apply the function 'f' to each characters of the string 's',
	passing its index as a first parameter.
    Each character is transmitted by address to 'f'
	so it can be modified if necessary.
	The difference between ft_striteri and ft_strmapi is that
	ft_striteri doesn't return anything and
	works directly on the original string.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
