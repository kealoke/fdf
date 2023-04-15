/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:06:09 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/27 19:57:53 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dst && src && dstsize == 0)
		return (slen);
	if (dstsize <= 0)
		return (slen);
	i = 0;
	while (dst[i] != '\0')
		i++;
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	j = 0;
	while (src[j] != '\0' && dstsize - dlen - 1 > j)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
