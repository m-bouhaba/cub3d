/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:08:44 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/09 00:27:38 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_function(char *read_buffer, int fd)
{
	char	*temp;
	int		read_return;

	read_return = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZEE + 1));
	if (temp == NULL)
		return (NULL);
	while (read_return != 0 && check_new_line(read_buffer) == -1)
	{
		read_return = read(fd, temp, BUFFER_SIZEE);
		if (read_return == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_return] = '\0';
		read_buffer = my_strjoin(read_buffer, temp);
	}
	free(temp);
	if (read_return == 0 && *read_buffer == '\0')
	{
		free(read_buffer);
		read_buffer = NULL;
	}
	return (read_buffer);
}

char	*next_line(char *buffer, int index_line)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	line = malloc (sizeof(char) * my_strlen(buffer + index_line) + 1);
	while (buffer[i + index_line])
	{
		line[j] = buffer[i + index_line];
		i++;
		j++;
	}
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_linee(int fd)
{
	static char	*read_buffer;
	char		*returned_line;
	int			index_line;

	if (fd < 0 || BUFFER_SIZEE <= 0)
		return (0);
	read_buffer = read_function(read_buffer, fd);
	if (!read_buffer)
	{
		free(read_buffer);
		return (NULL);
	}
	index_line = check_new_line(read_buffer);
	if (index_line == -1)
	{
		returned_line = read_buffer;
		read_buffer = NULL;
		return (returned_line);
	}
	returned_line = ft_substrr(read_buffer, 0, index_line + 1);
	read_buffer = next_line(read_buffer, index_line + 1);
	return (returned_line);
}
