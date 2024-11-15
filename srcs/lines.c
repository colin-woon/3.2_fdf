/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:46:36 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/15 16:11:30 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_img *img, t_pt start, t_pt end);
int	draw_line_horizontal(t_img *img, t_pt start, t_pt end);
int	draw_line_vertical(t_img *img, t_pt start, t_pt end);

/*
https://github.com/yassineoubihi/Fdf
Based on Bresenham's Line Drawing Algo, determine primary increment:

If (Change in Y > (Change in X)
- Steep slope (more vertical)
- Primary increment Y, Conditionally increment X

If (Change in X) > (Change in Y)
- Shallow slope (more horizontal)
- Primary increment X, Conditionally increment Y
-- Extra IF statement checks the offset of the coordinates ensuring left
to right drawing
 */
int	draw_line(t_img *img, t_pt start, t_pt end)
{
	if (fabsf(end.y - start.y) < fabsf(end.x - start.x))
	{
		if (start.x > end.x)
			return (draw_line_horizontal(img, end, start));
		return (draw_line_horizontal(img, start, end));
	}
	return (draw_line_vertical(img, start, end));
}

int	draw_line_horizontal(t_img *img, t_pt start, t_pt end)
{
	int		error_term;
	int		y_direction;
	t_pt	delta;
	t_pt	current;

	delta = subtract_vector(end, start);
	y_direction = 1;
	if (delta.y < 0)
		y_direction = -1;
	delta.y = fabsf(delta.y);
	error_term = 2 * delta.y - delta.x;
	current = start;
	while (current.x++ < end.x)
	{
		img_pix_put(img, current);
		if (error_term > 0)
		{
			current.y += y_direction;
			error_term += 2 * (delta.y - delta.x);
		}
		else
			error_term += 2 * delta.y;
		current.colour = get_pixel_colour(current, start, end, delta);
	}
	return (0);
}

int	draw_line_vertical(t_img *img, t_pt start, t_pt end)
{
	int		error_term;
	int		x_direction;
	t_pt	delta;
	t_pt	current;

	delta = subtract_vector(end, start);
	x_direction = 1;
	if (delta.x < 0)
		x_direction = -1;
	delta.x = fabsf(delta.x);
	error_term = 2 * delta.x - delta.y;
	current = start;
	while (current.y++ < end.y)
	{
		img_pix_put(img, current);
		if (error_term > 0)
		{
			current.x += x_direction;
			error_term += 2 * (delta.x - delta.y);
		}
		else
			error_term += 2 * delta.x;
		current.colour = get_pixel_colour(current, start, end, delta);
	}
	return (0);
}
