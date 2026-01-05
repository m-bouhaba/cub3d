/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:25:03 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/12/27 00:57:44 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_function(char *read_buffer, int fd, int buffer_size)
{
	char	*temp;
	int		read_return;

	read_return = 1;
	temp = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (temp == NULL)
		return (NULL);
	while (read_return != 0)
	{
		read_return = read(fd, temp, buffer_size);
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

char	*get_full_map(int fd)
{
	static char	*read_buffer;
	int			buffer_size;

	buffer_size = 1;
	if (fd < 0)
		return (NULL);
	read_buffer = read_function(read_buffer, fd, buffer_size);
	if (!read_buffer)
	{
		free(read_buffer);
		return (NULL);
	}
	return (read_buffer);
}
