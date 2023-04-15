/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:31:14 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:03:29 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf **fdf)
{
	int		x;
	int		y;
	int		z;
	char	**tmp;
	t_point	*new;
	t_point	*map_stack;

	tmp = (*fdf)->map;
	x = 0;
	y = 0;
	map_stack = NULL;
	while (y < (*fdf)->map_height)
	{
		while (x < (*fdf)->map_width)
		{
			z = tmp[y][x];
			new = (t_point *)my_malloc(sizeof(t_point));
			new->vx = (x / sqrt(2) + y / sqrt(2) * -1);
			new->vy = (x / sqrt(6) + y / sqrt(6) + z / sqrt(6) * -2);
			new->y = y;
			new->x = x;
			//tmp->vz = (z/sqrt(3)*-1 + y/-sqrt(3)*-1 + z/sqrt(3));
			new->vz = tmp[y][x];
			new->color = (*fdf)->color_map[y][x];
			new->next = NULL;
			new->prev = NULL;
			//ft_lstadd_back(&map_stack, new);
			ft_lstadd_front(&map_stack, new);
			x++;
		}
		x = 0;
		y++;
	}
	map_stack = ft_lstlast(map_stack);
	(*fdf)->map_stack = map_stack;
}
