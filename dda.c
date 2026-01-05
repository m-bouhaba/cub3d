/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:49:56 by mbouhaba          #+#    #+#             */
/*   Updated: 2026/01/05 13:50:17 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_f_c(t_cub *cub)
{
	cub->new_angle = (((cub->alpha + cub->marge) * PI) / 180) - \
	(((cub->alpha) * PI) / 180);
	cub->distance_of_ray = cub->distance_of_ray * cos(cub->new_angle);
	cub->dis_p_to_screen = (L3ARD / 2) / tan((30 * PI) / 180);
	cub->wall = ((STEP) * cub->dis_p_to_screen / cub->distance_of_ray);
	cub->cel = (L3ARD - cub->wall) / 2;
	cub->floor = (L3ARD - cub->wall) / 2;
}

int	convert_to_int(int R, int G, int B)
{
	return (R << 16 | G << 8 | B);
}

void	mlx_put(t_cub *cub, t_dda *dda, int i0, t_var *var)
{
	float	__y;

	calculate_wall_f_c(cub);
	cub->index = 0;
	while (cub->index <= cub->cel && cub->index < L3ARD)
	{
		my_mlx_pixel_put(cub, i0, cub->index,
			convert_to_int(var->cel[0], var->cel[1], var->cel[2]));
		cub->index++;
	}
	while (cub->index <= cub->cel + cub->wall && cub->index < L3ARD)
	{
		__y = (float)(cub->index - cub->cel) / (float)cub->wall;
		my_mlx_pixel_put(cub, i0, cub->index,
			get_colors(cub, dda->x0, __y, cub->path));
		cub->index++;
	}
	while (cub->index < L3ARD)
	{
		my_mlx_pixel_put(cub, i0, cub->index,
			convert_to_int(var->fl[0], var->fl[1], var->fl[2]));
		cub->index++;
	}
}

void	fun_dda(t_cub *cub, t_dda *dda, int i0, t_var *var)
{
	dda_1(dda, cub);
	xinc_yinc_conditions(cub, dda);
	cub->distance_of_ray = sqrt((pow((dda->x0 - cub->x * STEP), 2) + \
	pow((dda->y0 - cub->y * STEP), 2)));
	if (cub->state == 2 || cub->state == 3)
	{
		dda->x0 /= STEP;
		dda->x0 = fmod(dda->x0, 1);
	}
	else
	{
		dda->x0 = dda->y0 / STEP;
		dda->x0 = fmod(dda->x0, 1);
	}
	mlx_put(cub, dda, i0, var);
}

void	draw_images(t_cub *cub)
{
	int		i;
	t_dda	dda;
	t_var	*var;
	float	p;

	p = (float)60 / (float)TOL;
	var = cub->var;
	i = 0;
	cub->marge = -30.0;
	while (i < TOL)
	{
		dda.x0 = cub->x * STEP;
		dda.y0 = cub->y * STEP;
		dda.x1 = STEP * ((cub->x) + 100 * \
		cos(((cub->alpha + cub->marge) * PI) / 180));
		dda.y1 = STEP * ((cub->y) + 100 * \
		sin(((cub->alpha + cub->marge) * PI) / 180));
		fun_dda(cub, &dda, i, var);
		cub->marge += p;
		i++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_win, cub->mlx_img, 0, 0);
}
