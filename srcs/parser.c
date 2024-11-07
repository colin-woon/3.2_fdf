/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:51:06 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/07 18:55:23 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_file(t_data *data, char *filename);
char	*get_file(int fd, t_data *data);
int		count_columns(char *line);

// Also allocates memory for data->map
int	parse_file(t_data *data, char *filename)
{
	int		fd;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("File Open Error", 2);
		return (FILE_ERROR);
	}
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		return (MALLOC_ERROR);
	file = get_file(fd, data);
	if (file == NULL)
		return (FILE_ERROR);
	ft_striteri(file, newline_to_space);
	data->parsed_file = ft_split(file, ' ');
	free(file);
	if (close(fd) == -1)
	{
		ft_putendl_fd("File Close Error", 2);
		return (FILE_ERROR);
	}
	return (0);
}

char	*get_file(int fd, t_data *data)
{
	char	*line;
	char	*file;
	int		no_of_columns;

	line = "";
	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
	file[0] = '\0';
	data->map->height = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			no_of_columns = count_columns(line);
			if (!is_map_valid(no_of_columns, data))
				return (NULL);
			data->map->width = no_of_columns;
			data->map->height += 1;
			append_line_to_file(&line, &file);
		}
	}
	return (file);
}

int	count_columns(char *line)
{
	int		no_of_columns;
	char	**split_line;
	char	*line_dup;

	line_dup = ft_strdup(line);
	no_of_columns = 0;
	ft_striteri(line_dup, newline_to_space);
	split_line = ft_split(line_dup, ' ');
	free(line_dup);
	while (split_line[no_of_columns] != NULL)
		no_of_columns++;
	ft_free_2d_array(split_line);
	return (no_of_columns);
}
