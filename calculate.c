/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:07:06 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:07:23 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p_info	*calc_distance(t_p_info *draw_p)
{
	draw_p->dx = draw_p->next_x - draw_p->x;
	draw_p->dy = draw_p->next_y - draw_p->y;
	draw_p->ix = 1;
	draw_p->iy = 1;
	if (draw_p->dx < 0)
	{
		draw_p->ix = -1;
		draw_p->dx = draw_p->dx * -1;
	}
	if (draw_p->dy < 0)
	{
		draw_p->iy = -1;
		draw_p->dy = draw_p->dy * -1;
	}
	if (draw_p->dx < draw_p->dy)
	{
		draw_p->e = draw_p->dy * -1;
		draw_p->a = draw_p->dx * 2;
		draw_p->b = draw_p->dy * -2;
		draw_p->ax = 0;
		draw_p->ay = draw_p->iy;
		draw_p->bx = draw_p->ix;
		draw_p->by = 0;
	}
	else
	{
		draw_p->e = draw_p->dx * -1;
		draw_p->a = draw_p->dy * 2;
		draw_p->b = draw_p->dx * -2;
		draw_p->ax = draw_p->ix;
		draw_p->ay = 0;
		draw_p->bx = 0;
		draw_p->by = draw_p->iy;
	}
	return (draw_p);
}

t_p_info	*calc_point(t_point *tmp, t_p_info *draw_p, int flag, t_fdf *fdf)
{
	int		i;
	t_point	*tmp2;

	i = 0;
	tmp2 = tmp;
	if (flag == 0)
	{
		draw_p->start_x = tmp->vx;
		draw_p->start_y = tmp->vy;
		draw_p->x = tmp->vx;
		draw_p->y = tmp->vy;
		draw_p->next_x = tmp->prev->vx;
		draw_p->next_y = tmp->prev->vy;
	}
	if (flag == 1)
	{
		while (i < fdf->map_width)
		{
			tmp2 = tmp2->prev;
			i++;
		}
		if (!tmp)
			return (0);
		draw_p->next_x = tmp2->vx;
		draw_p->next_y = tmp2->vy;
	}
	draw_p = calc_distance(draw_p);
	return (draw_p);
}
