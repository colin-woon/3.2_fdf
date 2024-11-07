/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:30:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:28:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int dec_nbr, char specifier)
{
	char	*hexa_base;
	int		count;

	hexa_base = 0;
	if (specifier == 'x')
		hexa_base = "0123456789abcdef";
	else if (specifier == 'X')
		hexa_base = "0123456789ABCDEF";
	count = 0;
	if (dec_nbr >= 16)
	{
		count += ft_print_hexa(dec_nbr / 16, specifier);
		dec_nbr %= 16;
	}
	count += write(1, &hexa_base[dec_nbr], 1);
	return (count);
}
