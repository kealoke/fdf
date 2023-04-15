/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:14:19 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:18:01 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_sp(const char *str)
{
	int			type;
	long int	num;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	type = 1;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			type = type * -1;
		str++;
	}
	num = 0;
	while (*str != '\0' && '0' <= *str && *str <= '9')
	{
		if (type == 1 && long_check_max(str, num) == -1)
			return ((int)LONG_MAX);
		if (type == -1 && long_check_min(str, num) == -1)
			return ((int)LONG_MIN);
		num = (num * 10) + (*str++ - '0');
	}
	if (*str)
		error("atoi_error");
	return ((int)(num * type));
}

int	ft_atoi_base(char *str)
{
	char	*base1;
	char	*base2;
	int		i;
	int		j;
	int		result;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	i = 0;
	result = 0;
	while (str[i])
	{
		j = 0;
		while (base1[j])
		{
			if (str[i] == base1[j] || str[i] == base2[j])
			{
				result = result * (ft_strlen(base1)) + j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key(int key_code, t_fdf *fdf)
{
	if (key_code == ESC)
	{
		close_win(fdf);
	}
	return (0);
}

void	*my_malloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		error("malloc_error\n");
	return (res);
}
