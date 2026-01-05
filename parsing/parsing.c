/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:53:34 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:34:57 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "get_next_line.h"

void	ft_error3(t_pars *pars, char c)
{
	if (c == 'E')
		printf("ERROR\nEMPTY MAP\n");
	else if (c == 'M')
		printf("ERROR\n->> %s <<- IS AN UNKOWN ELEMENT\n", pars->token);
	else if (c == 'G')
		printf("ERROR\nTHE NUMBER YOU ENTERED IS OUT OF RGB RANGE[0.255]\n");
	else if (c == '1')
		printf("ERROR\nINVALID POSITION OF MAP\n");
	else if (c == 'H')
		printf("ERROR\nCHECK EXTENSION\n");
	exit (1);
}

t_pars	*get_token(t_pars *pars, char *line, int in)
{
	int		i;

	i = 0;
	pars->token = NULL;
	pars->i = in;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		if (line[i] == '1' && pars->n == 6)
			return (pars);
		if (line[i])
		{
			while (line[i] && line[i] != ' ' && line[i] != '\n')
			{
				pars->token = ft_strjoinn(pars->token, convert_to_str(line[i]));
				i++;
			}
			pars->j = i;
			check_token(pars);
			return (pars);
		}
	}
	return (pars);
}

t_pars	*init_pars(char *file)
{
	t_pars	*pars;
	int		fd;

	pars = malloc(sizeof(t_pars));
	fd = open(file, O_RDONLY);
	pars->full_map = get_full_map(fd);
	pars->token = NULL;
	pars->no = NULL;
	pars->so = NULL;
	pars->we = NULL;
	pars->ea = NULL;
	pars->f = NULL;
	pars->c = NULL;
	pars->i = 0;
	pars->n = 0;
	pars->player = 0;
	pars->f = (int *)malloc(sizeof(int) * 3);
	pars->c = (int *)malloc(sizeof(int) * 3);
	pars = split_map(pars, file);
	return (pars);
}

void	check_extension(char *file, t_pars *pars)
{
	int	len;

	len = ft_strlenn(file);
	if (file[--len] == 'b')
	{	
		if (file[--len] == 'u')
		{
			if (file[--len] == 'c')
			{
				if (file[--len] == '.')
					return ;
			}
			ft_error3(pars, 'H');
		}
		ft_error3(pars, 'H');
	}
	ft_error3(pars, 'H');
}

t_pars	*parsing(char *file)
{
	t_pars		*pars;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	pars = init_pars(file);
	check_extension(file, pars);
	pars = first_check(pars);
	pars = map_check(pars);
	return (pars);
}
