/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 02:09:44 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:05:53 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	wrdscnt(char const *s, char c)
{
	int	nmbr_of_wrds;

	nmbr_of_wrds = 0;
	while (*s)
	{
		if (*s == '\n')
			break ;
		if (*s == c)
			s++;
		else
		{
			nmbr_of_wrds++;
			while (*s && *s != c)
			{
				s++;
			}
		}
	}
	return (nmbr_of_wrds);
}

static int	wrdlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		if (*s != c)
			i++;
		s++;
	}
	return (i);
}

static char	*split_str(char const *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = wrdlen(s, c);
	str = malloc(j + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != c && s[i] != '\n' && s[i] && j > 0)
	{
		str[i] = s[i];
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_splitt(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (wrdscnt(s, c) + 1));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\n')
			i++;
		if (s[i] && s[i] != c && s[i] != '\n')
		{
			tab[j] = split_str(s + i, c);
			i = i + wrdlen(s + i, c);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
