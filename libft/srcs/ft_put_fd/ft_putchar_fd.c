/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:44:45 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:27:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
NAME
    ft_putchar_fd -- write character c on a specified file descriptor
SYNOPSIS
    void ft_putchar_fd(char c, int fd);
DESCRIPTION
    The ft_putchar_fd() function writes the character `c`
	on the file descriptor `fd`.
PARAMETERS
    c: character to write
    fd: file descriptor on which to write
RETURN VALUES
    ft_putchar_fd() does not return anything.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
