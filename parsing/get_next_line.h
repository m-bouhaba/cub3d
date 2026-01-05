/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:15:01 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:04:57 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZEE 20

char	*get_next_linee(int fd);
char	*my_strjoin(char *src, char *dst);
size_t	my_strlen(const char *str);
int		check_new_line(char *str);
char	*ft_substrr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpyy(char *dst, const char *src, size_t dstsize);

#endif
