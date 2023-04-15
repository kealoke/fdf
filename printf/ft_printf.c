/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:54:12 by yushimom          #+#    #+#             */
/*   Updated: 2022/11/14 12:55:52 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_fmt(va_list ap, const char fmt)
{
	int	len;

	len = 0;
	if (fmt == 'c')
		len += ft_char_print(va_arg(ap, int));
	else if (fmt == 's')
		len += ft_string_print(va_arg(ap, char *));
	else if (fmt == 'p')
		len += ft_pointer_print(va_arg(ap, unsigned long long), fmt);
	else if (fmt == 'd' || fmt == 'i')
		len += ft_int_print(va_arg(ap, int));
	else if (fmt == 'u')
		len += ft_unsigned_print(va_arg(ap, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		len += ft_hex_print(va_arg(ap, unsigned int), fmt);
	else if (fmt == '%')
		len += ft_persent_print();
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	int		i;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			len += ft_dec_fmt(ap, fmt[i + 1]);
			i++;
		}
		else
			len += ft_char_print(fmt[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
