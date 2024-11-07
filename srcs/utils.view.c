/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:40:47 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:56:59 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_xy_limits(t_map *map);

void	get_xy_limits(t_map *map)
{
	t_pt	*current;
	int		i;

	i = 0;
	while (i < map->width * map->height)
	{
		current = map->points + i;
		if (current->x < map->min_x)
			map->min_x = current->x;
		if (current->x > map->max_x)
			map->max_x = current->x;
		if (current->y < map->min_y)
			map->min_y = current->y;
		if (current->y > map->max_y)
			map->max_y = current->y;
		i++;
	}
}
