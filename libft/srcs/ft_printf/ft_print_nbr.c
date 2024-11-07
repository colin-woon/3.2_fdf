/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:42:06 by cwoon             #+#    #+#             */
/*   Updated: 2024/07/01 17:17:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nb)
{
	int		count;
	long	nbr;

	nbr = nb;
	count = 0;
	if (nbr < 0)
	{
		count += ft_print_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		count += ft_print_nbr(nbr / 10);
		nbr = nbr % 10;
	}
	count += ft_print_char(nbr + '0');
	return (count);
}
