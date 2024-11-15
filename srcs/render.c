/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:22:23 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/14 13:24:54 by cwoon            ###   ########.fr       */
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
/*
Starts drawing the lines from one point to the other,
adds the offset to convert the cartesian coordinates to
 2D graphic coordinates

(i % map->width != map->width - 1)
- excludes the last column to the right
- connect to the points on their right

(i < map->width * map->height - map->width)
- excludes those in the last row
- connect to the points beneath them
 */
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
similar to a 2D grid:
- y * line_len finds the nth row
- x * (bpp/8) finds the nth pixel (1byte = 8bits, /8 finds total bytes)
*(int)pixel	= sets the pixel colour
 */
void	img_pix_put(t_img *img, t_pt pt)
{
	char	*pixel;
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if (x < 0 || x >= D_WIDTH || y < 0 || y >= D_HEIGHT)
		return ;
	pixel = img->address + y * img->line_len + x * (img->bits_p_pixel / 8);
	*(int *)pixel = pt.colour;
}
