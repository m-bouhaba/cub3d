/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:48:33 by mbouhaba          #+#    #+#             */
/*   Updated: 2023/01/17 01:22:51 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		printf("Error \nfile not found\n");
		exit(0);
	}
}

char	*get_color_we(float _x, float _y, t_paths *path)
{
	int		x;
	int		y;
	char	*dst;

	x = (int)(_x * path->we.img_w) % path->we.img_w;
	y = (int)(_y * path->we.img_h) % path->we.img_h;
	dst = path->we.addr + (y * path->we.line_length + \
	x * (path->we.bits_per_pixel / 8));
	return (dst);
}

char	*get_color_ea(float _x, float _y, t_paths *path)
{
	int		x;
	int		y;
	char	*dst;

	x = (int)(_x * path->ea.img_w) % path->ea.img_w;
	y = (int)(_y * path->ea.img_h) % path->ea.img_h;
	dst = path->ea.addr + (y * path->ea.line_length + \
	x * (path->ea.bits_per_pixel / 8));
	return (dst);
}

int	get_colors(t_cub *data, float _x, float _y, t_paths *path)
{
	int		x;
	int		y;
	char	*dst;

	if (data->state == 2)
	{
		x = (int)(_x * path->no.img_w) % path->no.img_w;
		y = (int)(_y * path->no.img_h) % path->no.img_h;
		dst = path->no.addr + (y * path->no.line_length
				+ x * (path->no.bits_per_pixel / 8));
	}
	else if (data->state == 3)
	{
		x = (int)(_x * path->so.img_w) % path->so.img_w;
		y = (int)(_y * path->so.img_h) % path->so.img_h;
		dst = path->so.addr + (y * path->so.line_length + \
		x * (path->so.bits_per_pixel / 8));
	}
	else if (data->state == 1)
		dst = get_color_ea(_x, _y, path);
	else
		dst = get_color_we(_x, _y, path);
	return (*(unsigned int *)dst);
}
