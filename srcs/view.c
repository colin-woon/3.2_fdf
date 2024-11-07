/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:16:59 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:57:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	generate_iso_view(t_map *map);
t_map	*transform_map(t_map *map, t_matrix3x3 mat);
void	autoscale(t_map *map);
void	zoom(t_map *map, float_t factor);

/**
 * This function applies a series of rotations to the map to transform it into
 * an isometric view. The rotations are applied in the following order:
 * - Rotate around the X-axis by -π/2 radians.
 * - Rotate around the Y-axis by π/4 radians.
 * - Rotate around the X-axis by the ISO constant.
 */
void	generate_iso_view(t_map *map)
{
	rotate_x(map, -M_PI_2);
	rotate_y(map, M_PI_4);
	rotate_x(map, ISO);
}

t_map	*transform_map(t_map *map, t_matrix3x3 mat)
{
	int		i;
	t_pt	*current;

	i = 0;
	while (i < map->width * map->height)
	{
		current = map->points + i;
		*current = matrix_calc(mat, *current);
		i++;
	}
	map->basis_x = matrix_calc(mat, map->basis_x);
	map->basis_y = matrix_calc(mat, map->basis_y);
	map->basis_z = matrix_calc(mat, map->basis_z);
	return (map);
}

void	autoscale(t_map *map)
{
	float_t	scale_x;
	float_t	scale_y;

	map->min_x = 0;
	map->max_x = 0;
	map->min_y = 0;
	map->max_y = 0;
	get_xy_limits(map);
	scale_x = (D_WIDTH / 2 - MARGIN) / fmaxf(abs(map->max_x), abs(map->min_x));
	scale_y = (D_HEIGHT / 2 - MARGIN) / fmaxf(abs(map->max_y), abs(map->min_y));
	zoom(map, fminf(scale_x, scale_y));
}

void	zoom(t_map *map, float_t factor)
{
	t_matrix3x3	scale;

	scale = (t_matrix3x3)
	{
		factor, 0, 0,
		0, factor, 0,
		0, 0, factor
	};
	transform_map(map, scale);
}
