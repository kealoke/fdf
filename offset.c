/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:49:08 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 20:49:00 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_fdf **fdf)
{
	t_point	*tmp;

	tmp = (*fdf)->map_stack;
	while (tmp)
	{
		tmp->vx *= ((*fdf)->zoom / 2);
		tmp->vy *= ((*fdf)->zoom / 2);
		tmp = tmp->prev;
	}
}

void	offset(t_fdf **fdf)
{
	t_point	*tmp;

	(*fdf)->x_offset = (WIDTH - (*fdf)->map_width) / 2;
	(*fdf)->y_offset = (HEIGHT - (*fdf)->map_height) / 2;
	if ((*fdf)->map_width < (WIDTH / 10))
	{
		(*fdf)->zoom = 50;
		printf("zoom: %d\n", (*fdf)->zoom);
	}
	else
		(*fdf)->zoom = 8;
	zoom(fdf);
	tmp = (*fdf)->map_stack;
	while (tmp)
	{
		tmp->vx += (*fdf)->x_offset;
		tmp->vy += (*fdf)->y_offset;
		tmp = tmp->prev;
	}
}
