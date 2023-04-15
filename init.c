/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:41:37 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 20:28:36 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->mlx_win = NULL;
	fdf->map_height = 0;
	fdf->map_width = 0;
	fdf->zoom = 40;
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	fdf->color = 0xFFFFFF;
}

void	init_p_info(t_p_info *draw_point)
{
	draw_point->start_x = 0;
	draw_point->start_y = 0;
	draw_point->x = 0;
	draw_point->y = 0;
	draw_point->next_x = 0;
	draw_point->next_y = 0;
	draw_point->ix = 1;
	draw_point->iy = 1;
	draw_point->dx = 0;
	draw_point->dy = 0;
	draw_point->e = 0;
	draw_point->a = 0;
	draw_point->ax = 0;
	draw_point->ay = 0;
	draw_point->bx = 0;
	draw_point->by = 0;
	draw_point->b = 0;
}