/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:16:59 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/15 17:04:28 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	generate_iso_view(t_map *map);
t_map	*transform_map(t_map *map, t_matrix3x3 mat);
void	autoscale(t_map *map);
void	zoom(t_map *map, float_t factor);

/*
This function applies a series of rotations to the map to transform it into
an isometric view. The rotations are applied in the following order:

- Rotate around the X-axis by -π/2 radians.
	This rotates the map by 90degrees around the x-axis,
	effectively "tilting" the view.
	This helps create a 3D effect by projecting the z-axis into the 2D plane.

- Rotate around the Y-axis by π/4 radians.
	This rotates the map by 45degrees around the y-axis.
	This rotation helps align the view to show depth,
	bringing the 3D perspective by "rotating"
	what would otherwise be a flat view along the y-axis.

- Rotate around the X-axis by the ISO constant.
	If `ISO` is set to a specific angle for isometric projection (0.81647),
	this final rotation refines the view to achieve a classic
	isometric projection.

x-rotation for initial tilt,
y-rotation for side view,
x-rotation for final isometric alignment.
 */
void	generate_iso_view(t_map *map)
{
	rotate_x(map, -M_PI_2);
	rotate_y(map, M_PI_4);
	rotate_x(map, ISO);
}

t_map	*transform_map(t_map *map, t_matrix3x3 rotation_mat)
{
	int		i;
	t_pt	*current;

	i = 0;
	while (i < map->width * map->height)
	{
		current = map->points + i;
		*current = matrix_calc(rotation_mat, *current);
		i++;
	}
	map->basis_x = matrix_calc(rotation_mat, map->basis_x);
	map->basis_y = matrix_calc(rotation_mat, map->basis_y);
	map->basis_z = matrix_calc(rotation_mat, map->basis_z);
	return (map);
}

/*
Calculates the scaling factors for both the x and y dimensions
based on the map's current limits and the display dimensions. It then applies
the smaller of the two scaling factors to ensure the map fits within the display
while maintaining the aspect ratio.
 */
void	autoscale(t_map *map)
{
	float_t	factor_x;
	float_t	factor_y;

	map->min_x = 0;
	map->max_x = 0;
	map->min_y = 0;
	map->max_y = 0;
	get_xy_limits(map);
	factor_x = (D_WIDTH / 2 - MARGIN) / \
				fmaxf(abs(map->max_x), abs(map->min_x));
	factor_y = (D_HEIGHT / 2 - MARGIN) / \
				fmaxf(abs(map->max_y), abs(map->min_y));
	zoom(map, fminf(factor_x, factor_y));
}

/*
Multiplies each respective point coordinates to its factors
 */
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
