/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:42:25 by sel-ouaf          #+#    #+#             */
/*   Updated: 2026/01/05 13:34:18 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_error(t_pars *pars, char c)
{
	if (c == 'P')
	{
		if (pars->player > 1)
			printf("ERROR\nDUPLICATED PLAYER\n");
		else if (pars->player == 0)
			printf("ERROR\nNO PLAYER\n");
	}
	else if (c == 'N')
		printf("ERROR\nEMPTY LINE IN THE MAP\n");
	else if (c == 'U')
		printf("ERROR\nUNKOWN CHARACTER IN THE MAP\n");
	else if (c == 'M')
		printf("ERROR\nNO MAP HAS BEEN FOUND\n");
	else if (c == 'W')
		printf("ERROR\nMAP IS NOT SURROUNDED BY WALLS\n");
	else if (c == 'R')
		printf("ERROR\nUNKOWN CHARACTER IN RGB\n");
	else if (c == 'C')
		printf("ERROR\nTOO MANY COMMAS\n");
	exit (1);
}

void	check_chars(t_pars *pars)
{
	int	i;

	i = pars->i + 1;
	while (pars->splitted_map[i])
	{
		if (should_increment(pars->splitted_map[i]))
			i++;
		else
			break ;
	}
	if (!pars->splitted_map[i])
		ft_error(pars, 'M');
	while (pars->splitted_map[i])
	{
		if (check_line(pars->splitted_map[i], pars))
			i++;
		else
		{
			printf("Error\nError in map");
			exit (1);
		}
	}
}

int	where_to_stop(t_pars *pars)
{
	int	i;

	i = pars->i + 1;
	while (pars->splitted_map[i])
	{
		if (should_increment(pars->splitted_map[i]))
			i++;
		else
			break ;
	}
	return (i);
}

void	check_empty_spaces(t_pars *pars)
{
	int	i;
	int	j;

	i = where_to_stop(pars);
	while (pars->splitted_map[i])
	{
		j = 0;
		while (pars->splitted_map[i][j])
		{
			if (pars->splitted_map[i][j] == '0')
				check_around_zero_player(pars, i, j);
			if (pars->splitted_map[i][j] == 'S'
				|| pars->splitted_map[i][j] == 'E'
				|| pars->splitted_map[i][j] == 'W'
				|| pars->splitted_map[i][j] == 'N')
				check_around_zero_player(pars, i, j);
			j++;
		}
		i++;
	}
}

t_pars	*map_check(t_pars *pars)
{
	check_chars(pars);
	check_walls(pars);
	check_empty_spaces(pars);
	if (pars->player != 1)
		ft_error(pars, 'P');
	return (pars);
}
