/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:15:23 by cwoon             #+#    #+#             */
/*   Updated: 2024/07/01 19:32:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_nbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += ft_print_unsigned_nbr(nbr / 10);
		nbr = nbr % 10;
	}
	count += ft_print_char(nbr + '0');
	return (count);
}
