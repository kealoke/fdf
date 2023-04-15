/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:00 by yushimom          #+#    #+#             */
/*   Updated: 2022/11/07 19:58:52 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_print(int n)
{
	ft_putnbr(n);
	return (ft_get_len(n));
}

int	ft_unsigned_print(unsigned int n)
{
	ft_putnbr(n);
	return (ft_get_len(n));
}

int	ft_hex_print(unsigned long long n, const char fmt)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		ft_hex_print(n / 16, fmt);
		ft_hex_print(n % 16, fmt);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (fmt == 'X')
				ft_putchar(n - 10 + 'A');
			else
				ft_putchar(n - 10 + 'a');
		}
	}
	len += ft_get_hexlen(n);
	return (len);
}

int	ft_pointer_print(unsigned long long p, const char fmt)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (p == 0)
	{
		write(1, "0", 1);
		len += 1;
	}
	else
	{
		len += ft_hex_print(p, fmt);
	}
	return (len);
}
