/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:08:38 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:22:37 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*createbuffer(int fd, char *readingbuffer, char *buffer)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, readingbuffer, BUFFER_SIZE);
		if (ret == 0)
			return (buffer);
		else if (ret < 0)
			return (0);
		readingbuffer[ret] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		temp = buffer;
		buffer = ft_strjoin(temp, readingbuffer);
		free(temp);
		temp = 0;
		if (ft_strchr(readingbuffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*splittext(char *text)
{
	char	*buffer;
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i])
		i++;
	buffer = ft_substr(text, i + 1, ft_strlen(text));
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (0);
	}
	text[i + 1] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*reading;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reading = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!reading)
		return (0);
	line = createbuffer(fd, reading, buffer);
	free(reading);
	reading = 0;
	if (!line)
		return (0);
	buffer = splittext(line);
	return (line);
}
