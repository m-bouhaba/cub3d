/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:19:46 by mbouhaba          #+#    #+#             */
/*   Updated: 2023/01/08 20:17:08 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	scape_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
	{
		if (!ft_strncmp("NO ", str + i + 1, 3))
			return (1);
		else if (!ft_strncmp("SO ", str + i + 1, 3))
			return (2);
		else if (!ft_strncmp("WE ", str + i + 1, 3))
			return (3);
		else if (!ft_strncmp("EA ", str + i + 1, 3))
			return (4);
		else if (!ft_strncmp("F ", str + i + 1, 2))
			return (5);
		else if (!ft_strncmp("C ", str + i + 1, 2))
			return (6);
		i++;
	}
	return (0);
}

void	check_number_of_directions(t_var *var)
{
	if (var->count_no > 1 || var->count_so > 1 \
		|| var->count_we > 1 || var->count_ea > 1 \
		|| var->count_f > 1 || var->count_c > 1)
	{
		printf("Error\nmultiple count of directions in file\n");
		exit(0);
	}
}

// void	check_numb(char **line, t_var *var)
// {
// 	int	i;

// 	i = 0;
// 	null_var(var);
// 	while (line[i])
// 	{
// 		if (!ft_strncmp("NO ", line[i], 3) || scape_spaces(line[i]) == 1)
// 			var->count_no++;
// 		else if (!ft_strncmp("SO ", line[i], 3) || scape_spaces(line[i]) == 2)
// 			var->count_so++;
// 		else if (!ft_strncmp("WE ", line[i], 3) || scape_spaces(line[i]) == 3)
// 			var->count_we++;
// 		else if (!ft_strncmp("EA ", line[i], 3) || scape_spaces(line[i]) == 4)
// 			var->count_ea++;
// 		else if (!ft_strncmp("F ", line[i], 2) || scape_spaces(line[i]) == 5)
// 			var->count_f++;
// 		else if (!ft_strncmp("C ", line[i], 2) || scape_spaces(line[i]) == 6)
// 			var->count_c++;
// 		check_number_of_directions(var);
// 		i++;
// 	}
// }

void	check_caracters_in_map(char **map)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = check_numb_of_player(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '0' && map[i][j] != '1' \
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W' \
				&& map[i][j] != 'E' && map[i][j] != ' ' ) || count_player != 1)
			{
				printf("Error\nsome different caracters or \
multiple players in map\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	take_path(char **line, t_var *var, t_paths	*path)
{
	int	i;

	i = 0;
	while (line[i])
	{
		take_path_2(path, line, i, var);
		i++;
	}
}
