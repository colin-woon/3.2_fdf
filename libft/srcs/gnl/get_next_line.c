/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:26:05 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/15 17:02:06 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
void	create_linked_list(t_s_list **list_ptr, int fd);
void	append_str_node(t_s_list **list_ptr, char *str_buffer);
char	*get_line(t_s_list *node_ptr);
void	update_list_after_newline(t_s_list **list_ptr);

char	*get_next_line(int fd)
{
	static t_s_list	*list;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_linked_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	update_list_after_newline(&list);
	return (next_line);
}

void	create_linked_list(t_s_list **list_ptr, int fd)
{
	int		chars_read;
	char	*str_buffer;

	chars_read = 0;
	str_buffer = NULL;
	while (found_newline(*list_ptr) == 0)
	{
		str_buffer = malloc(BUFFER_SIZE + 1);
		if (str_buffer == NULL)
			return ;
		chars_read = read(fd, str_buffer, BUFFER_SIZE);
		if (chars_read == 0)
		{
			free(str_buffer);
			return ;
		}
		str_buffer[chars_read] = '\0';
		append_str_node(list_ptr, str_buffer);
	}
	return ;
}

void	append_str_node(t_s_list **list_ptr, char *str_buffer)
{
	t_s_list	*new_node;
	t_s_list	*last_node;

	last_node = find_last_node(*list_ptr);
	new_node = (t_s_list *)malloc(sizeof(t_s_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list_ptr = new_node;
	else
		last_node->next_node = new_node;
	*new_node = (t_s_list) \
	{.file_buffer = str_buffer, .next_node = NULL};
	return ;
}

char	*get_line(t_s_list *node_ptr)
{
	int		line_length;
	char	*new_line;

	if (node_ptr == NULL)
		return (NULL);
	line_length = strlen_to_newline(node_ptr);
	new_line = malloc(line_length + 1);
	if (new_line == NULL)
		return (NULL);
	copy_list_to_line(node_ptr, new_line);
	return (new_line);
}

void	update_list_after_newline(t_s_list **list_ptr)
{
	t_s_list	*last_node;
	t_s_list	*new_node_after_newline;
	int			i_src;
	int			i_dest;
	char		*str_buffer;

	str_buffer = malloc(BUFFER_SIZE + 1);
	new_node_after_newline = malloc(sizeof(t_s_list));
	if (str_buffer == NULL || new_node_after_newline == NULL || \
	list_ptr == NULL)
		return ;
	last_node = find_last_node(*list_ptr);
	i_src = 0;
	i_dest = 0;
	while (last_node->file_buffer[i_src] != '\0' && \
	last_node->file_buffer[i_src] != '\n')
		i_src++;
	while (last_node->file_buffer[i_src] != '\0' && \
	last_node->file_buffer[++i_src] != '\0')
		str_buffer[i_dest++] = last_node->file_buffer[i_src];
	str_buffer[i_dest] = '\0';
	*new_node_after_newline = (t_s_list) \
	{.file_buffer = str_buffer, .next_node = NULL};
	clear_list(list_ptr, new_node_after_newline, str_buffer);
}
/*
#include <stdio.h>
int main()
{
	int	fd, no_of_lines;
	char *line_of_str;

	no_of_lines = 1;
	fd = open("test.txt", O_RDONLY);

	while ((line_of_str = get_next_line(fd)))
	{
		printf("%d->%s", no_of_lines++, line_of_str);
		free(line_of_str);
	}
}
*/
