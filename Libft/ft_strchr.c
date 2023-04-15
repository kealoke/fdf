/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:15:23 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/28 14:11:02 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src != '\0')
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	if (!c)
		return ((char *)src);
	return (NULL);
}
