/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:02:40 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/08 23:46:46 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_pars	*first_check(t_pars *pars)
{
	int	i;

	i = 0;
	while (pars->splitted_map[i])
	{
		pars = get_token(pars, pars->splitted_map[i], i);
		if (pars->token)
		{
			if (pars->token[0] == '1')
				ft_error3(pars, '1');
		}
		free(pars->token);
		i++;
		if (pars->n == 6)
			break ;
	}
	if (pars->n != 6)
		ft_error_2(pars, 'E');
	return (pars);
}

char	*convert_to_str(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
