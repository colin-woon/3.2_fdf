/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:31 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 16:57:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_strjoin -- concatenate 2 strings in a new string
SYNOPSIS
    char *ft_strjoin(const char *s1, const char *s2);
DESCRIPTION
    Allocate (with malloc(3)) and returns a new string
	resulting from the concatenation of s1 and s2.
PARAMETERS
    s1: prefix string
    s2: suffix string
RETURN VALUES
    ft_strjoin() returns the new string; NULL if the memory allocation failed.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = (char *)malloc(sizeof(*tab) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (tab == 0)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
