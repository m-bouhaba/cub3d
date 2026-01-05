/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:08:22 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:22:11 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	src = (unsigned char *)s2;
	dst = (unsigned char *)s1;
	i = 0;
	while ((dst[i] || src[i]) && (i < n))
	{
		if (dst[i] < src[i])
			return (dst[i] - src[i]);
		else if (dst[i] > src[i])
			return (dst[i] - src[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	*k;
	int		i;

	i = 0;
	k = (char *)s;
	c = (char)c;
	if (c == '\0')
		return (k + ft_strlen(k));
	while (k[i] != '\0')
	{
		if (k[i] == c)
			return (k + i);
		i++;
	}
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	result;

	n = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * n);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
