/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4_map_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:49 by mbouhaba          #+#    #+#             */
/*   Updated: 2026/01/05 13:50:38 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extention(char *str)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (!s)
		return (0);
	if (ft_strncmp(s, ".cub", 4) != 0 || ft_strlen(s) != 4)
		return (0);
	return (1);
}

void	check_first_1(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' && map[i][j + 1] == ' ')
			j++;
		if (map[i][j] != ' ' && map[i][j] != '1')
		{
			printf("errooooor\ninvalid map1");
			exit(1);
		}
		i++;
	}
}

void	print_error(void)
{
	printf("Error\n");
	exit(1);
}

void	check_zero_and_player(char **map)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' \
			|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					print_error();
				else if ((j > ft_strlen(map[i + 1])) \
				|| (j > ft_strlen(map[i - 1])))
					print_error();
				else if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
					print_error();
			}
			j++;
		}
		i++;
	}
}

void	check_one(char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i][j])
	{
		if (line[i][j] != '1' && line[i][j] != ' ')
			print_error();
		j++;
	}
	while (line[++i])
	{
		j = 0;
		check_first_1(line);
		while (line[i][j])
		{
			if (line[i + 1] == NULL && (line[i][j] != '1' && line[i][j] != ' '))
				print_error();
			else if (line[i][j + 1] == '\0' \
			&& line[i][j] != '1' && line[i][j] != ' ')
				print_error();
		j++;
		}
	}
}
