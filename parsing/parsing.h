/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:49:48 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:38:11 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./get_next_line.h"

typedef struct pars {
	char	*full_map;
	char	**splitted_map;
	char	*token;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	int		player;
	int		i;
	int		j;
	int		n;
}	t_pars;

void	move_to_next(t_pars *pars);
void	skip_spaces(t_pars *pars);
t_pars	*init_pars(char *file);
t_pars	*get_token(t_pars *pars, char *line, int i);
t_pars	*parsing(char *file);
char	*get_full_map(int fd);
char	*ft_strjoinn(char *src, char *dst);
int		ft_strcmp(char *s1, char *s2);
int		count_lines(char *full_map);
t_pars	*check_path(t_pars *pars);
void	check_token(t_pars *pars);
char	*convert_to_str(char c);
t_pars	*copy_path(t_pars *pars, char *path);
int		ft_atoii(const char *str);
char	*get_number(t_pars *pars);
char	*get_number2(t_pars *pars);
int		not_allowed(char c);
t_pars	*check_rgb2(t_pars *pars);
t_pars	*check_number2(t_pars *pars, char **number);
t_pars	*check_number(t_pars *pars, char **number);
int		ft_isddigit(char c);
int		ft_strlenn(char *s);
void	check_how_m_n(t_pars *pars, char **number);
char	*copy(char *path, char *element);
t_pars	*check_rgb(t_pars *pars);
char	**ft_splitt(char const *s, char c);
t_pars	*map_check(t_pars *pars);
void	ft_error_2(t_pars *pars, char c);
void	ft_error(t_pars *pars, char c);
void	ft_error3(t_pars *pars, char c);
int		should_increment(char *line);
int		check_first_last(char *line, t_pars *pars);
t_pars	*split_map(t_pars *pars, char *file);
void	check_ones(char **lines, t_pars *pars);
void	check_walls(t_pars *pars);
t_pars	*check_elements(t_pars *pars);
void	check_around_zero_player(t_pars *pars, int i, int j);
t_pars	*first_check(t_pars *pars);
int		check_line(char *s, t_pars *pars);
int		check_characters(char *line, int i, t_pars *pars);
int		check_commas(char *line, int i, t_pars *pars);
int		check_error(char *line, int i, t_pars *pars);
#endif