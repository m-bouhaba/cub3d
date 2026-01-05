/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5_check_new_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:31:55 by mbouhaba          #+#    #+#             */
/*   Updated: 2023/01/17 01:20:26 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dup_map_utils(char **line)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (line[i])
	{
		i++;
		j++;
	}
	return (j);
}

char	**dup_map(char **line, t_cub *var)
{
	int		i;
	int		j;
	char	**dup;

	j = 0;
	var->count_line_in_map = dup_map_utils(line);
	if (var->count_line_in_map == 0)
	{
		printf("Error\nmissing map\n");
		exit(1);
	}
	dup = malloc(sizeof(char *) * (var->count_line_in_map + 1));
	if (!dup)
		return (NULL);
	i = 6;
	while (line[i])
	{
		dup[j] = line[i];
		i++;
		j++;
	}
	dup[j] = NULL;
	return (dup);
}

// int	check_the_begin_of_map(char *str)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] == 'N' && str[i + 1] == 'O') 
// 			|| (str[i] == 'S' && str[i + 1] == 'O') 
// 			|| (str[i] == 'W' && str[i + 1] == 'E') 
// 			|| (str[i] == 'E' && str[i + 1] == 'A') 
// 			|| str[i] == 'F' || str[i] == 'C')
// 			count++;
// 		if (count == 6 && str[i] == '\n')
// 			break ;
// 		i++;
// 	}
// 	return (i);
// }

// int	new_line_error(char *str)
// {
// 	int	i;

// 	i = check_the_begin_of_map(str);
// 	while (str[i] == '\n' || str[i] == ' ')
// 		i++;
// 	while (str[i])
// 	{
// 		if (str[i + 1] == '\n' && str[i + 2] == '\n')
// 		{
// 			i++;
// 			while (str[i] && str[i] == '\n')
// 				i++;
// 			if (str[i])
// 			{
// 				printf("Error\n");
// 				return (0);
// 			}
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

char	**r_file(char *str)
{
	int		fd;
	char	*line;
	char	*s;
	char	**split_line;
	char	*tmp;

	fd = open(str, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	s = ft_strdup("");
	while (line)
	{
		tmp = s;
		s = ft_strjoin(s, line);
		free(tmp);
		free (line);
		line = get_next_line(fd);
	}
		split_line = ft_split(s, '\n');
	free (s);
	return (split_line);
}
