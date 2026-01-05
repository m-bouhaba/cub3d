/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:08:18 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:22:27 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		count;
	int		i;
	char	*news;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	news = malloc(sizeof(char) * (count + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (i < count)
	{
		news[i] = s[i];
		i++;
	}
	news[i] = '\0';
	return (news);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	int		klen;
	char	*k;

	k = (char *)s;
	c = (char )c;
	if (c == '\0')
		return (k + ft_strlen(k));
	klen = ft_strlen(k);
	while (klen >= 0)
	{
		if (c == k[klen])
			return (k + klen);
		klen--;
	}
	return (NULL);
}
