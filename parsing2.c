/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:25:11 by mbouhaba          #+#    #+#             */
/*   Updated: 2026/01/05 13:52:09 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_numb_of_player(char **map)
{
	int	i;
	int	count_player;
	int	j;

	i = 0;
	count_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' \
			|| map[i][j] == 'S' || map[i][j] == 'E')
				count_player++;
			j++;
		}
		i++;
	}
	return (count_player);
}

int	count_comma(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	check_f_and_c(char *str)
{
	int	i;
	int	count;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '\n' && \
		!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' ')
		{
			printf("Error\n some different caracters\n");
			exit(0);
		}
		else if (str[i] == ',' && str[i + 1] == ',')
		{
			printf("Error\nmissing digit\n");
			exit(0);
		}
	}
	count = count_comma(str);
	if (count != 2)
	{
		printf("Error\n check number of comma\n");
		exit(0);
	}
}

void	split_c(char *str, t_var *var)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ',');
	while (split[++i])
		if (ft_strlen(split[i]) > 3)
			print_error();
	var->r = ft_atoi(split[0]);
	var->g = ft_atoi(split[1]);
	var->b = ft_atoi(split[2]);
	var->c_color = (var->r << 16) + (var->g << 8) + var->b;
	if ((var->r < 0 || var->r > 255) || (var->g < 0 \
		|| var->g > 255) || (var->b < 0 || var->b > 255))
	{
		printf("check min or max of color");
		exit(1);
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free (split);
}

void	split_f(char *str, t_var *var)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_split(str, ',');
	while (split[++i])
		if (ft_strlen(split[i]) > 3)
			print_error();
	var->r = ft_atoi(split[0]);
	var->g = ft_atoi(split[1]);
	var->b = ft_atoi(split[2]);
	var->f_color = (var->r << 16) + (var->g << 8) + var->b;
	if ((var->r < 0 || var->r > 255) || (var->g < 0 \
		|| var->g > 255) || (var->b < 0 || var->b > 255))
	{
		printf("check min or max of color");
		exit(1);
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free (split);
}
