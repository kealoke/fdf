/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:58:51 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/21 20:13:09 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	const char		*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
