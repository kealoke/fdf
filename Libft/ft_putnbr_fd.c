/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:48:27 by yushimom          #+#    #+#             */
/*   Updated: 2022/11/11 19:55:39 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnenbr_fd(long long n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putnenbr_fd(n / 10, fd);
	ft_putnenbr_fd(n % 10, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long long	n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n = nb;
		ft_putnenbr_fd(-n, fd);
		return ;
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd);
	ft_putnbr_fd(nb % 10, fd);
}
