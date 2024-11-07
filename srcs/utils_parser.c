/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:00:06 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/30 16:20:24 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	newline_to_space(unsigned int i, char *s);
int		is_map_valid(int new_columns, t_data *previous);
void	append_line_to_file(char **line, char **file);

void	newline_to_space(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}

int	is_map_valid(int new_columns, t_data *previous)
{
	if (previous->map->height != 0 && previous->map->width != new_columns)
	{
		ft_putendl_fd("Error. Map width inconsistent.", 2);
		return (0);
	}
	return (1);
}

// Safely appending by freeing memory and resetting line variable
void	append_line_to_file(char **line, char **file)
{
	char	*file_dup;

	file_dup = *file;
	*file = ft_strjoin(file_dup, *line);
	free(file_dup);
	free(*line);
	*line = "";
}
