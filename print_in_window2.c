/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_window2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:13:14 by mbouhaba          #+#    #+#             */
/*   Updated: 2026/01/09 12:43:18 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player2(int key, t_cub *player)
{
	int	angle;

	angle = 0;
	/* X11 keycodes on Linux: D=100, A=97, W=119, S=115 */
	if (key == 100)
		angle = 90;
	else if (key == 97)
		angle = -90;
	else if (key == 119)
		angle = 0;
	else if (key == 115)
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
	/* ESC on X11 is 65307 */
	if (key == 65307)
	{
		printf("\033[4;33m");
		printf("GAME HAS BEEN ENDED\n");
		exit(0);
	}
	if (key == 100 || key == 97 || key == 119 || key == 115)
		move_player2(key, player);
	/* Left/Right arrow keys on X11 */
	if (key == 65363)
		player->alpha += 5;
	if (key == 65361)
		player->alpha -= 5;
	draw_images(player);
	return (0);
}

/* Set key flag on press for continuous movement */
int key_press(int key, t_cub *player)
{
	/* ESC on X11 is 65307 */
	if (key == 65307)
	{
		printf("\033[4;33m");
		printf("GAME HAS BEEN ENDED\n");
		exit(0);
	}
	if (key == 119) /* W */
		player->key_w = 1;
	if (key == 115) /* S */
		player->key_s = 1;
	if (key == 97) /* A */
		player->key_a = 1;
	if (key == 100) /* D */
		player->key_d = 1;
	if (key == 65363) /* Right arrow */
		player->key_right = 1;
	if (key == 65361) /* Left arrow */
		player->key_left = 1;
	return (0);
}

/* Clear key flag on release */
int key_release(int key, t_cub *player)
{
	if (key == 119)
		player->key_w = 0;
	if (key == 115)
		player->key_s = 0;
	if (key == 97)
		player->key_a = 0;
	if (key == 100)
		player->key_d = 0;
	if (key == 65363)
		player->key_right = 0;
	if (key == 65361)
		player->key_left = 0;
	return (0);
}

/* Called each loop iteration by MLX: apply movement for held keys */
int loop_hook(t_cub *player)
{
	int moved = 0;
	float step = 1.0f / 12.0f; /* smaller step per loop to keep speed reasonable */
	float angle;

	if (player->key_w)
	{
		angle = player->alpha + 0;
		if (player->map[(int)(player->y + sin((angle * PI) / 180) * 0.5f)]
			[(int)(player->x + cos((angle * PI) / 180) * 0.5f)] == '0')
		{
			player->x += cos((angle * PI) / 180) * step;
			player->y += sin((angle * PI) / 180) * step;
			moved = 1;
		}
	}
	if (player->key_s)
	{
		angle = player->alpha + 180;
		if (player->map[(int)(player->y + sin((angle * PI) / 180) * 0.5f)]
			[(int)(player->x + cos((angle * PI) / 180) * 0.5f)] == '0')
		{
			player->x += cos((angle * PI) / 180) * step;
			player->y += sin((angle * PI) / 180) * step;
			moved = 1;
		}
	}
	if (player->key_d)
	{
		angle = player->alpha + 90;
		if (player->map[(int)(player->y + sin((angle * PI) / 180) * 0.5f)]
			[(int)(player->x + cos((angle * PI) / 180) * 0.5f)] == '0')
		{
			player->x += cos((angle * PI) / 180) * step;
			player->y += sin((angle * PI) / 180) * step;
			moved = 1;
		}
	}
	if (player->key_a)
	{
		angle = player->alpha - 90;
		if (player->map[(int)(player->y + sin((angle * PI) / 180) * 0.5f)]
			[(int)(player->x + cos((angle * PI) / 180) * 0.5f)] == '0')
		{
			player->x += cos((angle * PI) / 180) * step;
			player->y += sin((angle * PI) / 180) * step;
			moved = 1;
		}
	}
	if (player->key_right)
	{
		player->alpha += 3; /* rotate smoothly */
		moved = 1;
	}
	if (player->key_left)
	{
		player->alpha -= 3;
		moved = 1;
	}
	if (moved)
		draw_images(player);
	return (0);
}

int	exit_win(void *param)
{
	(void)param;
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

	/* initialize key states to 0 (not pressed) */
	var->key_w = 0;
	var->key_a = 0;
	var->key_s = 0;
	var->key_d = 0;
	var->key_left = 0;
	var->key_right = 0;
	draw_images(var);
	/* register key press and release handlers for continuous movement */
	mlx_hook(var->mlx_win, 2, 1L<<0, key_press, var);
	mlx_hook(var->mlx_win, 3, 1L<<1, key_release, var);
	/* destroy (window close) event */
	mlx_hook(var->mlx_win, 17, 0L, exit_win, var);
	/* per-frame loop hook to apply movement while keys are held */
	mlx_loop_hook(var->mlx_ptr, loop_hook, var);
	mlx_loop(var->mlx_ptr);
}
