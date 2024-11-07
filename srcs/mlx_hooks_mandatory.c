/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:16:43 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:53:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_data *data);
int	key_hook1(int keysym, t_data *data);

int	loop_hook(t_data *data)
{
	t_map	*map;
	t_pt	offset;

	if (data->window_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK);
	map = data->map;
	offset.x = D_WIDTH / 2;
	offset.y = D_HEIGHT / 2;
	offset.z = 0;
	draw_map(&data->img, map, offset);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, \
			data->img.buffer, 0, 0);
	return (0);
}

int	key_hook1(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	return (0);
}
