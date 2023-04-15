/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:15:20 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/27 19:55:23 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	const unsigned char	*slast;
	unsigned char		*dlast;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		slast = s + (n - 1);
		dlast = d + (n - 1);
		while (n-- > 0)
			*dlast-- = *slast--;
	}
	return (dst);
}
