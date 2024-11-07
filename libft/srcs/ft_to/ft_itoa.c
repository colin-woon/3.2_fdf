/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:49:15 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static	unsigned int	number_length(int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length = 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

/*
NAME
    ft_itoa -- convert an int to a string
SYNOPSIS
    char *ft_itoa(int n);
DESCRIPTION
    Allocate (with malloc(3)) and returns a string representing n.
    Negative numbers must be handled.
	Places the number backwards, absolute value gives non-negative value
	without regards to its sign
PARAMETERS
    n: int to convert
RETURN VALUES
    ft_itoa() returns the string representing n;
	NULL if the memory allocation failed.
 */
char	*ft_itoa(int n)
{
	int		length;
	int		sign;
	char	*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	length = number_length(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (str == 0)
		return (NULL);
	str[length] = '\0';
	length--;
	while (length >= 0)
	{
		str[length] = '0' + absolute_value(n % 10);
		n = absolute_value(n / 10);
		length--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
