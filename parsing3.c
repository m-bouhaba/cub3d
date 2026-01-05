/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:27:37 by mbouhaba          #+#    #+#             */
/*   Updated: 2023/01/12 18:07:43 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*parse_path(char *line, t_paths	*path)
{
	int		i;
	int		j;

	j = 0;
	i = 2;
	while (line[i] == ' ')
		i++;
	path->path = ft_substr(line, i, ft_strlen(line));
	while (path->path[j])
	{
		if (path->path[j + 1] == '\0' && path->path[j] == ' ')
		{
			printf("Error\nspace after path\n");
			exit(1);
		}
		j++;
	}
	return (path->path);
}

int	scape_s_before(char **line, int i)
{
	int	j;

	j = 0;
	while (line[i][j] && line[i][j] == ' ')
		j++;
	return (j);
}

void	take_path_f(t_var *var, char *str, int scape, t_paths *path)
{
	var->f = parse_path(str + scape, path);
	check_f_and_c(var->f);
	split_f(var->f, var);
}

void	take_path_c(t_var *var, char *str, int scape, t_paths *path)
{
	var->c = parse_path(str + scape, path);
	check_f_and_c(var->c);
	split_c(var->c, var);
}

void	take_path_2(t_paths	*path, char **line, int i, t_var *var)
{
	int	scape;

	scape = scape_s_before(line, i);
	if ((!ft_strncmp("NO ", line[i], 3) \
		|| scape_spaces(line[i]) == 1) && !var->no)
		var->no = parse_path(line[i] + scape, path);
	else if ((!ft_strncmp("SO ", line[i], 3) \
		|| scape_spaces(line[i]) == 2) && !var->so)
		var->so = parse_path(line[i] + scape, path);
	else if ((!ft_strncmp("WE ", line[i], 3) \
		|| scape_spaces(line[i]) == 3) && !var->we)
		var->we = parse_path(line[i] + scape, path);
	else if ((!ft_strncmp("EA ", line[i], 3) \
		|| scape_spaces(line[i]) == 4) && !var->ea)
		var->ea = parse_path(line[i] + scape, path);
	else if ((!ft_strncmp("F ", line[i], 2) \
	|| scape_spaces(line[i]) == 5) \
		&& !var->f)
		take_path_f(var, line[i], scape, path);
	else if ((!ft_strncmp("C ", line[i], 2) \
		|| scape_spaces(line[i]) == 6) && !var->c)
		take_path_c(var, line[i], scape, path);
}
