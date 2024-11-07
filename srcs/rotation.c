/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:21:15 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:56:05 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, float_t angle);
void	rotate_y(t_map *map, float_t angle);

void	rotate_x(t_map *map, float_t angle)
{
	t_matrix3x3	rot_x;

	rot_x = (t_matrix3x3)
	{
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)
	};
	transform_map(map, rot_x);
}

void	rotate_y(t_map *map, float_t angle)
{
	t_matrix3x3	rot_y;

	rot_y = (t_matrix3x3)
	{
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)
	};
	transform_map(map, rot_y);
}
