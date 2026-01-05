/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:08:06 by sel-ouaf          #+#    #+#             */
/*   Updated: 2026/01/05 13:49:23 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parsing/parsing.h"

int	main(int ac, char **av)
{
	char	**split_file;
	t_cub	game;
	t_var	var;
	t_paths	path;
	t_pars	*pars;

	if (ac == 2)
	{
		pars = parsing(av[1]);
		split_file = r_file(av[1]);
		game.map = dup_map(split_file, &game);
		take_path(split_file, &var, &path);
		free(path.path);
		var.fl = pars->f;
		var.cel = pars->c;
		print_in_window(&var, &path, &game);
	}
}
