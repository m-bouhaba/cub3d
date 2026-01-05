/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_window2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:13:14 by mbouhaba          #+#    #+#             */
/*   Updated: 2023/01/17 01:14:49 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player2(int key, t_cub *player)
{
	int	angle;

	angle = 0;
	if (key == 2)
		angle = 90;
	else if (key == 0)
		angle = -90;
	else if (key == 13)
		angle = 0;
	else if (key == 1)
		angle = 180;
	if (player->map[(int)(player->y
			+ sin(((player->alpha + angle) * PI)
				/ 180) / 2)][(int)(player->x
					+ cos(((player->alpha + angle) * PI)
						/ 180) / 2)] == '0')
	{
		player->x += cos(((player->alpha + angle) * PI) / 180) / 6;
		player->y += sin(((player->alpha + angle) * PI) / 180) / 6;
	}
}

int	mouve_player(int key, t_cub *player)
{
	if (key == 53)
	{
		printf("\033[4;33m");
		printf("GAME HAS BEEN ENDED\n");
		exit(0);
	}
	if (key == 2 || key == 0 || key == 13 || key == 1)
		move_player2(key, player);
	if (key == 124)
		player->alpha += 5;
	if (key == 123)
		player->alpha -= 5;
	draw_images(player);
	return (0);
}

int	exit_win(void)
{
	printf("\033[4;33m");
	printf("GAME HAS BEEN ENDED\n");
	exit(1);
}

void	print_in_window(t_var *data, t_paths *path, t_cub *var)
{
	var->mlx_ptr = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx_ptr, TOL, L3ARD, "CUB_S_M");
	var->mlx_img = mlx_new_image(var->mlx_ptr, TOL, L3ARD);
	var->addr1 = mlx_get_data_addr(var->mlx_img, &var->bits_per_pixel, \
	&var->line_length, &var->endian);
	first_position_and_angle_of_player(var, 0, 0);
	get_addr_textures(data, path, var);
	var->path = path;
	var->var = data;
	draw_images(var);
	mlx_hook(var->mlx_win, 2, 0, mouve_player, var);
	mlx_hook(var->mlx_win, 17, 0L << 2, exit_win, &var);
	mlx_loop(var->mlx_ptr);
}
