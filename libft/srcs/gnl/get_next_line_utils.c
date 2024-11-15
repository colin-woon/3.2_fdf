/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:26:02 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/15 17:02:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			found_newline(t_s_list *node_ptr);
t_s_list	*find_last_node(t_s_list *node_ptr);
int			strlen_to_newline(t_s_list *node_ptr);
void		copy_list_to_line(t_s_list *node_ptr, char *new_line);
void		clear_list(t_s_list **list_ptr, t_s_list *new_node_after_newline, \
char *str_buffer);

int	found_newline(t_s_list *node_ptr)
{
	int	i;

	if (node_ptr == NULL)
		return (0);
	i = 0;
	while (node_ptr != NULL)
	{
		i = 0;
		while (node_ptr->file_buffer[i] != '\0' && i < BUFFER_SIZE)
		{
			if (node_ptr->file_buffer[i] == '\n')
				return (1);
			i++;
		}
		node_ptr = node_ptr->next_node;
	}
	return (0);
}

t_s_list	*find_last_node(t_s_list *node_ptr)
{
	if (node_ptr == NULL)
		return (NULL);
	while (node_ptr->next_node != NULL)
		node_ptr = node_ptr->next_node;
	return (node_ptr);
}

int	strlen_to_newline(t_s_list *node_ptr)
{
	int	i;
	int	strlen_to_newline;

	if (node_ptr == NULL)
		return (0);
	strlen_to_newline = 0;
	i = 0;
	while (node_ptr != NULL)
	{
		i = 0;
		while (node_ptr->file_buffer[i] != '\0')
		{
			if (node_ptr->file_buffer[i] == '\n')
			{
				strlen_to_newline++;
				return (strlen_to_newline);
			}
			i++;
			strlen_to_newline++;
		}
		node_ptr = node_ptr->next_node;
	}
	return (strlen_to_newline);
}

void	copy_list_to_line(t_s_list *node_ptr, char *new_line)
{
	int	i_src;
	int	i_dest;

	if (node_ptr == NULL)
		return ;
	i_dest = 0;
	while (node_ptr != NULL)
	{
		i_src = 0;
		while (node_ptr->file_buffer[i_src] != '\0')
		{
			if (node_ptr->file_buffer[i_src] == '\n')
			{
				new_line[i_dest] = '\n';
				new_line[++i_dest] = '\0';
				return ;
			}
			new_line[i_dest++] = node_ptr->file_buffer[i_src++];
		}
		node_ptr = node_ptr->next_node;
	}
	new_line[i_dest] = '\0';
}

void	clear_list(t_s_list **list_ptr, t_s_list *new_node_after_newline, \
char *str_buffer)
{
	t_s_list	*temp_list;

	if (*list_ptr == NULL)
		return ;
	temp_list = 0;
	while (*list_ptr != NULL)
	{
		temp_list = (*list_ptr)->next_node;
		free((*list_ptr)->file_buffer);
		free(*list_ptr);
		*list_ptr = temp_list;
	}
	*list_ptr = NULL;
	if (new_node_after_newline->file_buffer[0] != '\0')
		*list_ptr = new_node_after_newline;
	else
	{
		free(str_buffer);
		free(new_node_after_newline);
	}
}
