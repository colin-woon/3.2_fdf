/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:23:55 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:51:18 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define ARG_ERROR -1
#define MALLOC_ERROR 1
#define FILE_ERROR -1
#define MLX_ERROR -1

#define D_WIDTH	1280
#define D_HEIGHT	720
#define RED	0x00FF0000
#define DRED	0x00660000
#define GREEN	0x0000FF00
#define BLUE	0x000000FF
#define DBLUE	0x00000066
#define PURPLE	0x00B491C8
#define WHITE	0x00FFFFFF
#define DGREEN	0x00006600
#define BLACK	0x00000000
#define GREY	0x00888888
#define DGREY	0x00333333
#define GROUND_COLOUR	RED
#define HIGH_COLOUR	PURPLE
#define LOW_COLOUR		DBLUE
#define ISO	0.8167
#define MARGIN	100

typedef struct s_img
{
	void	*buffer;
	char	*address;
	int		bits_p_pixel;
	int		line_len;
	int		endian;
}	t_img;
typedef struct s_pt
{
	float_t	x;
	float_t	y;
	float_t	z;
	int		colour;
}	t_pt;

// pt_arr = points
// x_dim = width
// y_dim = height
// min_z = min_height
// max_z = max_height
// base_i = basis_x
// base_j = basis_y
// base_k = basis_z
typedef struct s_map
{
	t_pt	*points;
	int		width;
	int		height;
	int		point_gap;
	int		min_z;
	int		max_z;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	t_pt	basis_x;
	t_pt	basis_y;
	t_pt	basis_z;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_img	img;
	t_map	*map;
	char	**parsed_file;
	int		animate_on;
	t_map	*origin_map;
}	t_data;

typedef struct s_matrix3x3
{
	float_t	c1r1;
	float_t	c1r2;
	float_t	c1r3;
	float_t	c2r1;
	float_t	c2r2;
	float_t	c2r3;
	float_t	c3r1;
	float_t	c3r2;
	float_t	c3r3;
}	t_matrix3x3;

// Utils Colour
int		get_gradient_colour(t_pt cur, t_pt start, t_pt end);
float_t	get_percentage(int start, int end, int cur);
int		get_colour_channel(int start, int end, float_t percentage);
int		get_pixel_colour(t_pt cur, t_pt start, t_pt end, t_pt delta);

// Utils Parser
void	newline_to_space(unsigned int i, char *s);
int		is_map_valid(int new_columns, t_data *previous);
void	append_line_to_file(char **line, char **file);

// Utils Math
t_pt	matrix_calc(t_matrix3x3 mat, t_pt pt);
t_pt	add_vector(t_pt pt1, t_pt pt2);
t_pt	subtract_vector(t_pt pt1, t_pt pt2);

// Utils View
void	get_xy_limits(t_map *map);

// Parser
int		parse_file(t_data *data, char *filename);
char	*get_file(int fd, t_data *data);
int		count_columns(char *line);

// Generate Map
t_map	*generate_map(t_data *data);
void	fill_map(t_data *data, t_map *map);
void	set_height_range(t_map *map, t_pt *current);
void	set_point_colours(t_map *map);
t_map	*save_original_map(t_data *data);

// View
void	generate_iso_view(t_map *map);
t_map	*transform_map(t_map *map, t_matrix3x3 mat);
void	autoscale(t_map *map);
void	zoom(t_map *map, float_t factor);

// Rotation
void	rotate_x(t_map *map, float_t angle);
void	rotate_y(t_map *map, float_t angle);

// Rendering
void	render_background(t_img *img, int colour);
void	draw_map(t_img *img, t_map *map, t_pt offset);
void	img_pix_put(t_img *img, t_pt pt);

// Lines
int		draw_line(t_img *img, t_pt start, t_pt end);
int		draw_line_low(t_img *img, t_pt start, t_pt end);
int		draw_line_high(t_img *img, t_pt start, t_pt end);

// MLX
int		start_mlx(t_data *data);
int		close_window(t_data *data);

// Hooks Mandatory
int		loop_hook(t_data *data);
int		key_hook1(int keysym, t_data *data);

// debug
void	print_img(t_img *img);
void	print_pt(t_pt *pt);
void	print_map(t_map *map);
void	print_data(t_data *data);
void	print_matrix3x3(t_matrix3x3 *matrix);
