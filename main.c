/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:55:06 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:29:23 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_fdf	*create_map(t_map_line *map_stack, t_fdf *fdf)
{
	int			i;
	int			j;
	t_map_line	*tmp;
	char		**split_line;
	char		**map;
	int			**color_map;

	tmp = map_stack;
	color_map = NULL;
	split_line = NULL;
	map = (char **)my_malloc(sizeof(char *) * ft_lstsize(map_stack));
	color_map = (int **)my_malloc(sizeof(int *) * ft_lstsize(map_stack));
	i = 0;
	j = 0;
	while (tmp)
	{
		split_line = ft_split(tmp->line, ' ');
		while (split_line[j])
		{
			j++;
		}
		map[i] = (char *)my_malloc(sizeof(char) * j);
		color_map[i] = (int *)my_malloc(sizeof(int) * j);
		j = 0;
		while (split_line[j])
		{
			if (ft_strchr(split_line[j], ','))
			{
				map[i][j] = ft_atoi(ft_split(split_line[j], ',')[0]);
				color_map[i][j] = ft_atoi_base(ft_split(split_line[j], ',')[1]);
			}
			else
			{
				map[i][j] = ft_atoi(split_line[j]);
				color_map[i][j] = 0xFFFFFF;
			}
			j++;
		}
		if (fdf->map_width == 0)
			fdf->map_width = j;
		if (j != fdf->map_width)
			error("map_error");
		i++;
		tmp = tmp->next;
	}
	fdf->map_height = i;
	fdf->map = map;
	fdf->color_map = color_map;
	return (fdf);
}

t_fdf	*read_map(int fd, t_fdf *fdf)
{
	char		*read_str;
	int			i;
	t_map_line	*line_stack;
	t_map_line	*new;

	read_str = NULL;
	line_stack = NULL;
	i = 0;
	while (1)
	{
		new = (t_map_line *)my_malloc(sizeof(t_map_line));
		new->line = get_next_line(fd);
		if (!new->line)
			break ;
		new->next = NULL;
		i++;
		ft_lstadd_back_ml(&line_stack, new);
	}
	free(new);
	fdf = create_map(line_stack, fdf);
	return (fdf);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (argc != 2)
		error("usage: ./fdf [map]");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("open_error");
	fdf = (t_fdf *)my_malloc(sizeof(t_fdf));
	init_fdf(fdf);
	fdf = read_map(fd, fdf);
	iso(&fdf);
	draw(fdf);
	argc = 1;
	free(fdf);
	close(fd);
}
