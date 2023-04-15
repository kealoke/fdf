/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:05:31 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/27 20:07:00 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		num = num * (-1);
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*c;
	long int	num;
	int			len;

	num = n;
	len = get_len(num);
	if (n < 0)
		num *= (-1);
	c = ft_calloc(len + 1, sizeof(char));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (num == 0)
		*c = '0';
	while (num > 0)
	{
		c[--len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		c[0] = '-';
	return (c);
}
