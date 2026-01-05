/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:07:25 by sel-ouaf          #+#    #+#             */
/*   Updated: 2023/01/17 01:19:49 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	null_var(t_var *var)
{
	var->count_no = 0;
	var->count_so = 0;
	var->count_we = 0;
	var->count_ea = 0;
	var->count_f = 0;
	var->count_c = 0;
	var->no = 0;
	var->so = 0;
	var->we = 0;
	var->ea = 0;
	var->f = 0;
	var->c = 0;
}

void	first_position_and_angle_of_player(t_cub *var, int i, int j)
{
	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (ft_strchr("NSWE", var->map[i][j]))
			{
				var->x = j + 0.5;
				var->y = i + 0.5;
				if (var->map[i][j] == 'N')
					var->alpha = 270;
				else if (var->map[i][j] == 'S')
					var->alpha = 90;
				else if (var->map[i][j] == 'W')
					var->alpha = 180;
				else if (var->map[i][j] == 'E')
					var->alpha = 0;
				var->map[i][j] = '0';
				break ;
			}
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr1 + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	xpm_files(t_var *data, t_paths *path, t_cub *cub)
{
	path->no.xpm_file = mlx_xpm_file_to_image(cub->mlx_ptr,
			data->no, &path->no.img_w, &path->no.img_h);
	path->so.xpm_file = mlx_xpm_file_to_image(cub->mlx_ptr,
			data->so, &path->so.img_w, &path->so.img_h);
	path->we.xpm_file = mlx_xpm_file_to_image(cub->mlx_ptr,
			data->we, &path->we.img_w, &path->we.img_h);
	path->ea.xpm_file = mlx_xpm_file_to_image(cub->mlx_ptr,
			data->ea, &path->ea.img_w, &path->ea.img_h);
}

void	get_addr_textures(t_var *data, t_paths *path, t_cub *cub)
{
	xpm_files(data, path, cub);
	if (!path->no.xpm_file || !path->so.xpm_file \
	|| !path->we.xpm_file || !path->ea.xpm_file)
	{
		printf ("TEXTURE: file not exist\n");
		exit (0);
	}
	path->no.addr = mlx_get_data_addr(path->no.xpm_file,
			&path->no.bits_per_pixel, &path->no.line_length, &path->no.endian);
	path->so.addr = mlx_get_data_addr(path->so.xpm_file,
			&path->so.bits_per_pixel, &path->so.line_length, &path->so.endian);
	path->we.addr = mlx_get_data_addr(path->we.xpm_file,
			&path->we.bits_per_pixel, &path->we.line_length, &path->we.endian);
	path->ea.addr = mlx_get_data_addr(path->ea.xpm_file,
			&path->ea.bits_per_pixel, &path->ea.line_length, &path->ea.endian);
}
