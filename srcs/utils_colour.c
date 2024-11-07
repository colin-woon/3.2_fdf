/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:49:26 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:54:33 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_gradient_colour(t_pt cur, t_pt start, t_pt end);
float_t	get_percentage(int start, int end, int cur);
int		get_colour_channel(int start, int end, float_t percentage);
int		get_pixel_colour(t_pt cur, t_pt start, t_pt end, t_pt delta);

// Using Linear Interpolation (need to research)
int	get_gradient_colour(t_pt cur, t_pt start, t_pt end)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	percentage = get_percentage(fabsf(start.z), fabsf(end.z), fabsf(cur.z));
	red = get_colour_channel((start.colour >> 16) & 0xFF, \
			(end.colour >> 16) & 0xFF, percentage);
	green = get_colour_channel((start.colour >> 8) & 0xFF, \
			(end.colour >> 8) & 0xFF, percentage);
	blue = get_colour_channel(start.colour & 0xFF, \
			end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | (blue));
}

// Returns the current position relative to the height range (z-axis) in %
float_t	get_percentage(int start, int end, int cur)
{
	float_t	cur_position;
	float_t	diff;

	diff = end - start;
	if (diff == 0)
		return (1.0);
	cur_position = cur - start;
	return (cur_position / diff);
}

int	get_colour_channel(int start, int end, float_t percentage)
{
	int	colour_channel;

	colour_channel = (1 - percentage) * start + percentage * end;
	return (colour_channel);
}

int	get_pixel_colour(t_pt cur, t_pt start, t_pt end, t_pt delta)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (cur.colour == end.colour)
		return (cur.colour);
	if (delta.x > delta.y)
		percentage = get_percentage(start.x, end.x, cur.x);
	else
		percentage = get_percentage(start.y, end.y, cur.y);
	red = get_colour_channel((start.colour >> 16) & 0xFF, \
			(end.colour >> 16) & 0xFF, percentage);
	green = get_colour_channel((start.colour >> 8) & 0xFF, \
			(end.colour >> 8) & 0xFF, percentage);
	blue = get_colour_channel(start.colour & 0xFF, \
			end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | (blue));
}
