/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:15:30 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:56:37 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start_mlx(t_data *data);
int	close_window(t_data *data);

int	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_putendl_fd("Error: connection to X Server failed", 2);
		return (MLX_ERROR);
	}
	data->window_ptr = mlx_new_window(data->mlx_ptr, D_WIDTH, D_HEIGHT, "FdF");
	if (data->window_ptr == NULL)
	{
		ft_putendl_fd("Error: failed to create new window", 2);
		return (MLX_ERROR);
	}
	data->img.buffer = mlx_new_image(data->mlx_ptr, D_WIDTH, D_HEIGHT);
	data->img.address = mlx_get_data_addr(data->img.buffer, \
			&data->img.bits_p_pixel, &data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->window_ptr, DestroyNotify, 0, close_window, data);
	mlx_hook(data->window_ptr, KeyPress, 1, key_hook1, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	data->window_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.buffer);
	mlx_destroy_display(data->mlx_ptr);
	free(data->map->points);
	free(data->map);
	free(data->origin_map->points);
	free(data->origin_map);
	free(data->mlx_ptr);
	ft_free_2d_array(data->parsed_file);
	exit(0);
	return (0);
}
