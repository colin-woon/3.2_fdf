/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:06:09 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:28:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexaull(uintptr_t ptr_address)
{
	int		count;
	char	*hexa_base;

	count = 0;
	hexa_base = "0123456789abcdef";
	if (ptr_address >= 16)
	{
		count += ft_print_hexaull(ptr_address / 16);
		ptr_address %= 16;
	}
	count += write(1, &hexa_base[ptr_address], 1);
	return (count);
}

int	ft_print_address(void *ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_print_hexaull((uintptr_t)ptr);
	return (count);
}
