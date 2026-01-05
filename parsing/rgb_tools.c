/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:30:36 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:37:47 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_pars	*check_rgb(t_pars *pars)
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
	check_number(pars, number);
	pars->n++;
	while (number[i])
	{
		free(number[i]);
		i++;
	}
	free(number);
	return (pars);
}

t_pars	*check_number2(t_pars *pars, char **number)
{
	int	i;
	int	j;

	i = 0;
	while (number[i])
	{
		j = ft_atoii(number[i]);
		if (j < 0 || j > 255)
			ft_error3(pars, 'G');
		pars->c[i] = j;
		i++;
	}
	return (pars);
}

int	check_characters(char *line, int i, t_pars *pars)
{
	while (line[i])
	{
		while (not_allowed(line[i]))
			i++;
		if (line[i] && !not_allowed(line[i]))
			ft_error(pars, 'R');
	}
	return (1);
}

int	check_commas(char *line, int i, t_pars *pars)
{
	int	c;

	c = 0;
	while (line[i])
	{
		if (line[i] == ',')
			c++;
		i++;
	}
	if (c > 2)
		ft_error(pars, 'C');
	if (c < 2)
		ft_error_2(pars, 'C');
	return (1);
}

void	ft_error_2(t_pars *pars, char c)
{
	(void)pars;
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		printf("ERROR\nTHERE IS AN EMPTINESS AROUND THE PLAYER\n");
	else if (c == '0')
		printf("ERROR\nTHERE IS A RISK OF REACHING AN EMPTY SPOT\n");
	else if (c == 'F')
		printf("ERROR\nCAN'T OPEN A FILE\n");
	else if (c == 'E')
	{
		if (pars->n > 6)
			printf("ERROR\nTHERE IS A DUPLICATED ELEMENTS\n");
		else if (pars->n < 5)
			printf("ERROR\nTHERE IS A MISSING ELEMENT\n");
	}
	else if (c == 'C')
		printf("ERROR\nNOT ENOUGH INFOS FOR RGB\n");
	exit (1);
}
