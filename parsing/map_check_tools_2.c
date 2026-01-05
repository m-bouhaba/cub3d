/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:46:57 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/09 00:01:42 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_walls(t_pars *pars)
{
	int		i;
	char	**lines;
	int		j;

	i = pars->i + 1;
	while (pars->splitted_map[i])
	{
		if (should_increment(pars->splitted_map[i]))
			i++;
		else
			break ;
	}
	while (pars->splitted_map[i])
	{
		j = 0;
		lines = ft_splitt(pars->splitted_map[i], ' ');
		check_ones(lines, pars);
		while (lines[j])
			free(lines[j++]);
		free(lines);
		i++;
	}
}

void	check_around_zero_player(t_pars *pars, int i, int j)
{
	if (pars->splitted_map[i][j - 1] == ' ')
		ft_error_2(pars, pars->splitted_map[i][j]);
	if (pars->splitted_map[i][j + 1] == ' ')
		ft_error_2(pars, pars->splitted_map[i][j]);
	if (j <= ft_strlenn(pars->splitted_map[i + 1]))
	{
		if (pars->splitted_map[i + 1][j] == ' ')
			ft_error_2(pars, pars->splitted_map[i][j]);
	}
	else
		ft_error_2(pars, pars->splitted_map[i][j]);
	if (j <= ft_strlenn(pars->splitted_map[i - 1]))
	{
		if (pars->splitted_map[i - 1][j] == ' ')
			ft_error_2(pars, pars->splitted_map[i][j]);
	}
	else
		ft_error_2(pars, pars->splitted_map[i][j]);
}

int	is_allowed(char c)
{
	if (c == '\n' || c == ' ')
		return (1);
	return (0);
}
