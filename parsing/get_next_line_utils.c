/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:09:23 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/09 00:25:52 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*my_strjoin(char *src, char *dst)
{
	size_t	i;
	size_t	j;
	size_t	dlenght;
	size_t	slenght;
	char	*new_buffer;

	i = 0;
	j = 0;
	slenght = my_strlen(src);
	dlenght = my_strlen(dst);
	new_buffer = (char *)malloc(sizeof(char) * (slenght + dlenght) + 1);
	if (src)
	{
		while (src[j] != 0)
			new_buffer[i++] = src[j++];
	}
	j = 0;
	while (dst[j] != 0)
		new_buffer[i++] = dst[j++];
	free(src);
	new_buffer[i] = '\0';
	return (new_buffer);
}

char	*ft_substrr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = my_strlen(s);
	if (start > my_strlen(s))
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if (strlen - start >= len)
		substr = (char *)malloc((len + 1) * sizeof(char));
	else
		substr = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpyy(substr, (s + start), (len + 1));
	return (substr);
}

size_t	ft_strlcpyy(char *dst, const char *src, size_t dstsize)
{
	size_t		src_lenght;
	size_t		j;

	src_lenght = my_strlen(src);
	if ((dstsize < 1))
		return (src_lenght);
	j = 0;
	while ((src[j]) && (j < (dstsize - 1)))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (src_lenght);
}
