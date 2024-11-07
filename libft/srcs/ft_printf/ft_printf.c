/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:55:40 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:28:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_format(va_list argp, const char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(argp, int));
	else if (specifier == 's')
		count += ft_print_string(va_arg(argp, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(va_arg(argp, int));
	else if (specifier == 'u')
		count += ft_print_unsigned_nbr(va_arg(argp, unsigned int));
	else if (specifier == '%')
		count += ft_print_char('%');
	else if (specifier == 'p')
		count += ft_print_address(va_arg(argp, void *));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hexa(va_arg(argp, unsigned int), specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(argp, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += printf_format(argp, format[i]);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(argp);
	return (count);
}
