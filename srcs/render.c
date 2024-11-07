/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:22:23 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:52:48 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_background(t_img *img, int colour);
void	draw_map(t_img *img, t_map *map, t_pt offset);
void	img_pix_put(t_img *img, t_pt pt);

void	render_background(t_img *img, int colour)
{
	int	row;
	int	col;

	row = 0;
	while (row < D_HEIGHT)
	{
		col = 0;
		while (col < D_WIDTH)
		{
			img_pix_put(img, (t_pt){col, row, 0, colour});
			col++;
		}
		row++;
	}
}

void	draw_map(t_img *img, t_map *map, t_pt offset)
{
	int		i;
	t_pt	pt;
	t_pt	neighbour_right;
	t_pt	neighbour_down;
	t_pt	*current;

	i = 0;
	while (i < map->width * map->height)
	{
		current = map->points + i;
		pt = add_vector(*current, offset);
		if (i % map->width != map->width - 1)
		{
			neighbour_right = add_vector(*(current + 1), offset);
			draw_line(img, pt, neighbour_right);
		}
		if (i < map->width * map->height - map->width)
		{
			neighbour_down = add_vector(*(current + map->width), offset);
			draw_line(img, pt, neighbour_down);
		}
		i++;
	}
}

/*
Pixel seems to be assigned twice:
pixel		= (locates the memory address of where the pixel should be placed)
*(int)pixel	= sets the pixel colour
 */
void	img_pix_put(t_img *img, t_pt pt)
{
	char	*pixel;
	int		x;
	int		y;

	x = round(pt.x);
	y = round(pt.y);
	if (x < 0 || x >= D_WIDTH || y < 0 || y >= D_HEIGHT)
		return ;
	pixel = img->address + y * img->line_len + x * (img->bits_p_pixel / 8);
	*(int *)pixel = pt.colour;
}
