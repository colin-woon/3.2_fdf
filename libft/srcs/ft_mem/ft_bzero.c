/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:10:44 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Sets a block of memory to 0. Be zero.
Input: Generic pointer `s`, Number of bytes to be zeroed `n`
Output: None
Sets each byte in a memory block to 0.
Typically used to initialize a memory block to zero,
such as allocating dynamic memory or resetting data structures
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
