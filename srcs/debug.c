#include "fdf.h"
#include <stdio.h>

void print_img(t_img *img);
void print_pt(t_pt *pt);
void print_map(t_map *map);
void print_data(t_data *data);
void print_matrix3x3(t_matrix3x3 *matrix);

// Function to print t_img
void print_img(t_img *img)
{
    printf("Image Buffer: %p\n", img->buffer);
    printf("Address: %s\n", img->address);
    printf("Bits Per Pixel: %d\n", img->bits_p_pixel);
    printf("Line Length: %d\n", img->line_len);
    printf("Endian: %d\n", img->endian);
}

// Function to print t_pt
void print_pt(t_pt *pt)
{
    printf("Point (x, y, z): (%f, %f, %f)\n", pt->x, pt->y, pt->z);
    printf("Colour: %d\n", pt->colour);
}

// Function to print t_map
void print_map(t_map *map)
{
    printf("Map Width: %d\n", map->width);
    printf("Map Height: %d\n", map->height);
    printf("Point Gap: %d\n", map->point_gap);
    printf("Min Z: %d\n", map->min_z);
    printf("Max Z: %d\n", map->max_z);
    printf("Min X: %d\n", map->min_x);
    printf("Max X: %d\n", map->max_x);
    printf("Min Y: %d\n", map->min_y);
    printf("Max Y: %d\n", map->max_y);
    printf("Basis X: ");
    print_pt(&map->basis_x);
    printf("Basis Y: ");
    print_pt(&map->basis_y);
    printf("Basis Z: ");
    print_pt(&map->basis_z);
    // Printing all points in the map (assume points is an array)
    for (int i = 0; i < map->width * map->height; i++)
    {
        printf("Point %d: ", i);
        print_pt(&map->points[i]);
    }
}

// Function to print t_data
void print_data(t_data *data)
{
    printf("MLX Pointer: %p\n", data->mlx_ptr);
    printf("Window Pointer: %p\n", data->window_ptr);
    printf("Animate On: %d\n", data->animate_on);
    printf("Parsed File: \n");
    for (int i = 0; data->parsed_file[i]; i++)
    {
        printf("%s\n", data->parsed_file[i]);
    }
    printf("Image:\n");
    print_img(&data->img);
    printf("Map:\n");
    print_map(data->map);
    printf("Origin Map:\n");
    print_map(data->origin_map);
}

// Function to print t_matrix3x3
void print_matrix3x3(t_matrix3x3 *matrix)
{
    printf("Matrix 3x3:\n");
    printf("%f %f %f\n", matrix->c1r1, matrix->c2r1, matrix->c3r1);
    printf("%f %f %f\n", matrix->c1r2, matrix->c2r2, matrix->c3r2);
    printf("%f %f %f\n", matrix->c1r3, matrix->c2r3, matrix->c3r3);
}
