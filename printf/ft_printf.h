/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:54:30 by yushimom          #+#    #+#             */
/*   Updated: 2022/11/07 19:59:49 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_char_print(int c);
void	ft_putstr(char *str);
int		ft_string_print(char *str);
void	ft_putnbr(long long nb);
int		ft_get_len(long long num);
int		ft_get_hexlen(unsigned long long num);
int		ft_int_print(int n);
int		ft_unsigned_print(unsigned int n);
int		ft_hex_print(unsigned long long n, const char fmt);
int		ft_pointer_print(unsigned long long p, const char fmt);
int		ft_persent_print(void);
int		ft_dec_fmt(va_list ap, const char fmt);
int		ft_printf(const char *fmt, ...);

#endif