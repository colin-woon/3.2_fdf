/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:55:35 by cwoon             #+#    #+#             */
/*   Updated: 2024/07/08 16:50:49 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_nbr(int nb);
int	ft_print_unsigned_nbr(unsigned int nbr);
int	ft_print_hexa(unsigned int dec_nbr, char specifier);
int	ft_print_address(void *ptr_address);
int	ft_printf(const char *format, ...);

#endif
