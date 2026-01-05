/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:42:21 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/09 00:27:29 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_token(t_pars *pars)
{
	if (pars->token)
	{	
		if (ft_strcmp(pars->token, "NO") || ft_strcmp(pars->token, "WE")
			|| ft_strcmp(pars->token, "SO") || ft_strcmp(pars->token, "EA")
			|| ft_strcmp(pars->token, "F") || ft_strcmp(pars->token, "C"))
			pars = check_elements(pars);
		else
			ft_error3(pars, 'M');
	}
}

t_pars	*check_elements(t_pars *pars)
{
	if (ft_strlenn(pars->token) == 2)
		pars = check_path(pars);
	if (ft_strlenn(pars->token) == 1 && ft_strcmp(pars->token, "C"))
		pars = check_rgb2(pars);
	if (ft_strlenn(pars->token) == 1 && ft_strcmp(pars->token, "F"))
		pars = check_rgb(pars);
	return (pars);
}

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	not_allowed(char c)
{
	if (c == ',' || c == '\n')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_pars	*split_map(t_pars *pars, char *file)
{
	int	n_lines;
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!pars->full_map)
		ft_error3(pars, 'E');
	n_lines = count_lines(pars->full_map);
	pars->splitted_map = (char **)malloc(sizeof(char *)
			* (count_lines(pars->full_map) + 1));
	while (n_lines > i)
	{
		pars->splitted_map[i] = get_next_linee(fd);
		i++;
	}
	pars->splitted_map[i] = NULL;
	return (pars);
}
