/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:38:57 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/15 23:21:59 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strjoinn(char *src, char *dst)
{
	size_t	i;
	size_t	j;
	int		dlenght;
	int		slenght;
	char	*new_buffer;

	i = 0;
	j = 0;
	slenght = ft_strlenn(src);
	dlenght = ft_strlenn(dst);
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
	free(dst);
	new_buffer[i] = '\0';
	return (new_buffer);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlenn(s1) != ft_strlenn(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(char *full_map)
{
	int		lines;
	int		i;

	i = 0;
	lines = 0;
	while (full_map[i] != '\0')
	{
		if (full_map[i] == '\n')
			lines++;
		i++;
	}
	lines++;
	return (lines);
}

int	ft_isddigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoii(const char *str)
{
	int		sign;
	int		nbr;
	int		i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == 31 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (nbr * sign);
}
