/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:01:39 by sel-ouaf          #+#    #+#             */
/*   Updated: 2026/01/05 13:34:47 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_pars	*copy_path(t_pars *pars, char *path)
{
	if (ft_strcmp(pars->token, "NO"))
		pars->no = copy(path, pars->no);
	else if (ft_strcmp(pars->token, "SO"))
		pars->so = copy(path, pars->so);
	else if (ft_strcmp(pars->token, "EA"))
		pars->ea = copy(path, pars->ea);
	else if (ft_strcmp(pars->token, "WE"))
		pars->we = copy(path, pars->we);
	return (pars);
}

t_pars	*fill_path(t_pars *pars, char *path)
{
	if (ft_strcmp(pars->token, "NO"))
	{
		pars->no = malloc(sizeof(char) * (ft_strlenn(path) + 1));
		pars = copy_path(pars, path);
		pars->n++;
	}
	else if (ft_strcmp(pars->token, "SO"))
	{
		pars->so = malloc(sizeof(char) * (ft_strlenn(path) + 1));
		pars = copy_path(pars, path);
		pars->n++;
	}
	else if (ft_strcmp(pars->token, "WE"))
	{
		pars->we = malloc(sizeof(char) * (ft_strlenn(path) + 1));
		pars = copy_path(pars, path);
		pars->n++;
	}
	else if (ft_strcmp(pars->token, "EA"))
	{
		pars->ea = malloc(sizeof(char) * (ft_strlenn(path) + 1));
		pars = copy_path(pars, path);
		pars->n++;
	}
	return (pars);
}

t_pars	*check_path(t_pars *pars)
{
	char	*path;
	int		fd;

	path = NULL;
	while (pars->splitted_map[pars->i][pars->j] == ' ')
		pars->j++;
	if (pars->splitted_map[pars->i][pars->j])
	{
		while (pars->splitted_map[pars->i][pars->j] &&
			pars->splitted_map[pars->i][pars->j] != '\n')
		{
			path = ft_strjoinn(path,
					convert_to_str(pars->splitted_map[pars->i][pars->j]));
			pars->j++;
		}
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_2(pars, 'F');
	else
		pars = fill_path(pars, path);
	free(path);
	return (pars);
}

char	*copy(char *path, char *element)
{
	int	i;

	i = 0;
	while (path[i])
	{
		element[i] = path[i];
		i++;
	}
	element[i] = '\0';
	return (element);
}
