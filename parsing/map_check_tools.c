/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:43:16 by sel-ouaf          #+#    #+#             */
/*   Updated: 2026/01/05 13:33:54 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	allowed_chars(char c, t_pars *pars)
{
	if (c == ' ' || c == '\n' || c == '1' || c == '0')
		return (1);
	if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
	{
		pars->player++;
		if (pars->player != 1)
			ft_error(pars, 'P');
		return (1);
	}
	return (0);
}

int	check_line(char *s, t_pars *pars)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '\n')
			ft_error(pars, 'N');
		if (!allowed_chars(s[i], pars))
			ft_error(pars, 'U');
		i++;
	}
	return (1);
}

int	should_increment(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return (1);
	while (line[i] == ' ' || line[i] == '\n')
		i++;
	if (!line[i])
		return (1);
	return (0);
}

int	check_first_last(char *line, t_pars *pars)
{
	int	i;

	i = ft_strlenn(line);
	if (line[i - 1] != '1')
		ft_error(pars, 'W');
	if (line[0] != '1')
		ft_error(pars, 'W');
	return (1);
}

void	check_ones(char **lines, t_pars *pars)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i])
			if (check_first_last(lines[i], pars))
				i++;
	}
}
