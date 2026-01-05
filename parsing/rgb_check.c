/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:03:26 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:34:15 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_error(char *line, int i, t_pars *pars)
{
	check_characters(line, i, pars);
	check_commas(line, i, pars);
	return (1);
}

void	check_how_m_n(t_pars *pars, char **number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i][0] == '\n')
			break ;
		i++;
	}
	if (i != 3)
		ft_error_2(pars, 'C');
}

t_pars	*check_rgb2(t_pars *pars)
{
	char	**number;
	int		i;

	i = 0;
	number = NULL;
	while (pars->splitted_map[pars->i][pars->j] == ' ')
		pars->j++;
	if (check_error(pars->splitted_map[pars->i], pars->j, pars))
		number = ft_splitt((pars->splitted_map[pars->i] + pars->j), ',');
	check_how_m_n(pars, number);
	check_number2(pars, number);
	i = 0;
	while (number[i])
	{
		free(number[i]);
		i++;
	}
	free(number);
	pars->n++;
	return (pars);
}

t_pars	*check_number(t_pars *pars, char **number)
{
	int	i;
	int	j;

	i = 0;
	while (number[i])
	{
		j = ft_atoii(number[i]);
		if (j < 0 || j > 255)
			ft_error3(pars, 'G');
		pars->f[i] = j;
		i++;
	}
	return (pars);
}
