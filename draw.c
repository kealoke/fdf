/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:46:42 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:07:03 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

t_p_info	*put_pixel(t_data img, t_p_info *draw_p, t_point *tmp)
{
	if (draw_p->x > 0 && draw_p->x < WIDTH && draw_p->y > 0
		&& draw_p->y < HEIGHT)
	{
		my_mlx_pixel_put(&img, draw_p->x, draw_p->y, tmp->color);
	}
	draw_p->x += draw_p->ax;
	draw_p->y += draw_p->ay;
	draw_p->e += draw_p->a;
	if (draw_p->e >= 0)
	{
		draw_p->x += draw_p->bx;
		draw_p->y += draw_p->by;
		draw_p->e += draw_p->b;
	}
	return (draw_p);
}

void	draw_col_line(t_fdf *fdf, t_data img, t_point *tmp)
{
	t_p_info	*draw_p;
	int			flag;

	flag = 1;
	draw_p = (t_p_info *)my_malloc(sizeof(t_p_info));
	draw_p->start_x = tmp->vx;
	draw_p->start_y = tmp->vy;
	draw_p->x = tmp->vx;
	draw_p->y = tmp->vy;
	if (tmp->y + 1 >= fdf->map_height)
		return ;
	draw_p = calc_point(tmp, draw_p, flag, fdf);
	while (1)
	{
		draw_p = put_pixel(img, draw_p, tmp);
		if (draw_p->start_y < draw_p->next_y && draw_p->y >= draw_p->next_y)
			break ;
		if (draw_p->start_y > draw_p->next_y && draw_p->y <= draw_p->next_y)
			break ;
	}
	free(draw_p);
}

void	draw_row_line(t_fdf *fdf, t_data img)
{
	t_point		*tmp;
	t_p_info	*draw_p;
	int			flag;

	flag = 0;
	tmp = fdf->map_stack;
	draw_p = (t_p_info *)my_malloc(sizeof(t_p_info));
	init_p_info(draw_p);
	while (tmp->prev != NULL)
	{
		draw_p = calc_point(tmp, draw_p, flag, fdf);
		while (1)
		{
			draw_p = put_pixel(img, draw_p, tmp);
			if (draw_p->x >= draw_p->next_x)
				break ;
			if (draw_p->start_y > draw_p->next_y && draw_p->y <= draw_p->next_y)
				break ;
			if (draw_p->start_y < draw_p->next_y && draw_p->y >= draw_p->next_y)
				break ;
		}
		draw_col_line(fdf, img, tmp);
		tmp = tmp->prev;
	}
	free(draw_p);
}

void	draw(t_fdf *fdf)
{
	t_data	img;

	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	offset(&fdf);
	draw_row_line(fdf, img);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, img.img, 0, 0);
	mlx_hook(fdf->mlx_win, 17, 0, close_win, fdf);
	mlx_hook(fdf->mlx_win, 2, 0, key, fdf);
	mlx_loop(fdf->mlx);
}
