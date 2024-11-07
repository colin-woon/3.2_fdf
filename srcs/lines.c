/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:46:36 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/30 18:00:31 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_img *img, t_pt start, t_pt end);
int	draw_line_low(t_img *img, t_pt start, t_pt end);
int	draw_line_high(t_img *img, t_pt start, t_pt end);

int	draw_line(t_img *img, t_pt start, t_pt end)
{
	if (fabsf(end.y - start.y) < fabsf(end.x - start.x))
	{
		if (start.x > end.x)
			return (draw_line_low(img, end, start));
		return (draw_line_low(img, start, end));
	}
	if (start.y > end.y)
		return (draw_line_high(img, start, end));
	return (draw_line_high(img, start, end));
}

int	draw_line_low(t_img *img, t_pt start, t_pt end)
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

int	draw_line_high(t_img *img, t_pt start, t_pt end)
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
