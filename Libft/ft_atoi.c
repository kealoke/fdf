/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:12:44 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/08 13:01:44 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../fdf.h"

long int	long_check_max(const char *str, long int num)
{
	long int	ov_div;

	ov_div = LONG_MAX / 10;
	if (ov_div < num)
		return (-1);
	if (ov_div == num && *str > '7')
		return (-1);
	return (num);
}

long int	long_check_min(const char *str, long int num)
{
	long int	ov_div;

	ov_div = LONG_MAX / 10;
	if (ov_div < num)
		return (-1);
	if (ov_div == num && *str > '8')
		return (-1);
	return (num);
}

int	ft_atoi(const char *str)
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
	return ((int)(num * type));
}
