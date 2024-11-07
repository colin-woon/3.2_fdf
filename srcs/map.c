/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:32:01 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/30 17:05:26 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*generate_map(t_data *data);
void	fill_map(t_data *data, t_map *map);
void	set_height_range(t_map *map, t_pt *current);
void	set_point_colours(t_map *map);
t_map	*save_original_map(t_data *data);

t_map	*generate_map(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->min_z = 0;
	map->max_z = 0;
	map->basis_x = (t_pt){1, 0, 0, 0x0};
	map->basis_y = (t_pt){0, 1, 0, 0x0};
	map->basis_z = (t_pt){0, 0, 1, 0x0};
	map->points = malloc(map->width * map->height * sizeof(t_pt));
	if (map->points == NULL)
		return (NULL);
	map->point_gap = 10;
	fill_map(data, map);
	set_point_colours(map);
	save_original_map(data);
	return (map);
}

// Still using Cartesian Coordinate System, 
// this will calculate offset later based on this project's context
// map_point.y = -map->point_gap * map->height / 2;
// map_point.x = -map->point_gap * map->width / 2;
// 
// To calculate the exact point of a matrix in a 1D array
// current = map->points + i_row * map->width + i_col;
//   j →  0    1    2    3    4
// i ↓  +----+----+----+----+----+
//   0  | P0 | P1 | P2 | P3 | P4 |
//      +----+----+----+----+----+
//   1  | P5 | P6 | P7 | P8 | P9 |
//      +----+----+----+----+----+
//   2  | P10| P11| P12| P13| P14|
//      +----+----+----+----+----+
//   3  | P15| P16| P17| P18| P19|
//      +----+----+----+----+----+
// map->pt_arr =	[ P0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
// 					P11, P12, P13, P14, P15, P16, P17, P18, P19 ]
void	fill_map(t_data *data, t_map *map)
{
	int		i_row;
	int		i_col;
	t_pt	*current;
	t_pt	map_point;

	map_point.z = 0;
	map_point.y = -map->point_gap * map->height / 2;
	i_row = 0;
	while (i_row < map->height)
	{
		map_point.x = -map->point_gap * map->width / 2;
		i_col = 0;
		while (i_col < map->width)
		{
			current = map->points + i_row * map->width + i_col;
			*current = map_point;
			current->z = ft_atoi(data->parsed_file[i_row * map->width + i_col]);
			set_height_range(map, current);
			current->colour = GROUND_COLOUR;
			map_point.x += map->point_gap;
			i_col++;
		}
		map_point.y += map->point_gap;
		i_row++;
	}
}

void	set_height_range(t_map *map, t_pt *current)
{
	if (current->z < map->min_z)
		map->min_z = current->z;
	if (current->z > map->max_z)
		map->max_z = current->z;
}

void	set_point_colours(t_map *map)
{
	t_pt	ground;
	t_pt	max;
	t_pt	min;
	t_pt	*current;
	int		i;

	ground = (t_pt){0, 0, 0, GROUND_COLOUR};
	max = (t_pt){0, 0, map->max_z, HIGH_COLOUR};
	min = (t_pt){0, 0, map->min_z, LOW_COLOUR};
	i = 0;
	while (i < map->width * map->height)
	{
		current = map->points + i;
		if (current->z > 0)
			current->colour = get_gradient_colour(*current, ground, max);
		if (current->z < 0)
			current->colour = get_gradient_colour(*current, ground, min);
		i++;
	}
}

t_map	*save_original_map(t_data *data)
{
	t_pt	*current;
	int		i;

	data->origin_map = malloc(sizeof(t_map));
	if (data->origin_map == NULL)
		return (NULL);
	data->origin_map->points = malloc(data->map->width \
			* data->map->height * sizeof(t_pt));
	if (data->origin_map->points == NULL)
		return (NULL);
	i = 0;
	while (i < data->map->width * data->map->height)
	{
		current = data->map->points + i;
		*(data->origin_map->points + i) = *current;
		i++;
	}
	return (data->origin_map);
}
