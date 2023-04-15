/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:03:36 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:10:42 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
//#include "./printf/ft_printf.h"

# define HEIGHT 1080
# define WIDTH 1920
# define ESC 53

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}						t_map_line;

typedef struct s_point
{
	int					color;
	double				x;
	double				y;
	double				vx;
	double				vy;
	double				vz;
	struct s_point		*prev;
	struct s_point		*next;

}						t_point;

typedef struct s_p_info
{
	double				start_x;
	double				start_y;
	double				x;
	double				y;
	double				z;
	double				next_x;
	double				next_y;
	int					ix;
	int					iy;
	int					dx;
	int					dy;
	int					e;
	int					a;
	int					b;
	int					ax;
	int					ay;
	int					bx;
	int					by;

}						t_p_info;

// typedef struct s_camera
// {
// 	int mode;

// }t_camera;

typedef struct s_fdf
{
	void				*mlx;
	void				*mlx_win;
	char				**map;
	int					**color_map;
	t_point				*map_stack;
	char				**iso_map;
	int					map_width;
	int					map_height;
	int					zoom;
	int					x_offset;
	int					y_offset;
	// int z_offset;
	// int z_scale;
	int					color;
	//int projection;
}						t_fdf;

//calculate.c
t_p_info	*calc_distance(t_p_info *draw_p);
t_p_info	*calc_point(t_point *tmp, t_p_info *draw_p, int flag, t_fdf *fdf);

//draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_p_info	*put_pixel(t_data img, t_p_info *draw_p, t_point *tmp);
void	draw_col_line(t_fdf *fdf, t_data img, t_point *tmp);
void	draw_row_line(t_fdf *fdf, t_data img);
void	draw(t_fdf *fdf);

//error.c
void					error(char *error_str);

//free.c
void					free_array(char **array);

//init
void					init_fdf(t_fdf *fdf);
void					init_p_info(t_p_info *draw_point);

//iso
void					iso(t_fdf **fdf);

//list
t_point					*ft_lstnew_point(char *split_char);
t_point					*ft_lstlast(t_point *lst);
t_map_line				*ft_lstlast_ml(t_map_line *lst);
void					ft_lstadd_back(t_point **lst, t_point *new);
void					ft_lstadd_back_ml(t_map_line **lst, t_map_line *new);
void					ft_lstadd_front(t_point **lst, t_point *new);
int						ft_lstsize(t_map_line *lst);

//draw
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					draw(t_fdf *fdf);

//offset
void					offset(t_fdf **fdf);
void					zoom(t_fdf **fdf);
double					get_max_point(t_fdf **fdf);
double					get_min_point(t_fdf **fdf);

//utils
int						ft_atoi_sp(const char *str);
int						ft_atoi_base(char *str);
int						close_win(t_fdf *fdf);
int						key(int key_code, t_fdf *fdf);
void *my_malloc(size_t size);


t_map_line				*ft_lstnew_mapline(char *read_line);
#endif