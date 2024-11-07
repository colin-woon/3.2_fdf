/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:33:59 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/19 19:39:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
		free(matrix[i++]);
	free(matrix);
}
