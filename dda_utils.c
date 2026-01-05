/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:59:04 by mbouhaba          #+#    #+#             */
/*   Updated: 2023/01/17 00:27:42 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_1(t_dda *dda, t_cub *cub)
{
	cub->dx = dda->x1 - dda->x0;
	cub->dy = dda->y1 - dda->y0;
	if (abs(cub->dx) > abs(cub->dy))
		cub->step = abs(cub->dx);
	else
		cub->step = abs(cub->dy);
	cub->xinc = cub->dx / cub->step;
	cub->yinc = cub->dy / cub->step;
}

void	break_condition(t_cub *cub, t_dda *dda)
{
	while (1)
	{
		dda->x0 = dda->x0 + cub->xinc;
		dda->y0 = dda->y0 + cub->yinc;
		if ((dda->x0 / STEP) < 0 || \
		((dda->x0 / STEP) > ft_strlen(cub->map[(int)(dda->y0 / STEP)]) \
		|| (dda->y0 / STEP) < 0 || (dda->y0 / STEP) > cub->count_line_in_map))
			break ;
		if (cub->map[(int)((dda->y0) / STEP)][(int)((dda->x0) / STEP)] != '0')
			break ;
	}
	dda->x0 -= cub->xinc;
	dda->y0 -= cub->yinc;
}

void	xinc_yinc_conditions(t_cub *cub, t_dda *dda)
{
	break_condition(cub, dda);
	while (1)
	{
		if (cub->map[(int)((dda->y0 + cub->yinc / 100) \
		/ STEP)][(int)(dda->x0 / STEP)] != '0')
		{
			if (cub->yinc < 0)
				cub->state = 2;
			else
				cub->state = 3;
			break ;
		}
		if (cub->map[(int)((dda->y0) / STEP)] \
		[(int)((dda->x0 + cub->xinc / 100) / STEP)] != '0')
		{
			if (cub->xinc < 0)
				cub->state = 0;
			else
				cub->state = 1;
			break ;
		}
		dda->x0 = dda->x0 + cub->xinc / 100;
		dda->y0 = dda->y0 + cub->yinc / 100;
	}
}
