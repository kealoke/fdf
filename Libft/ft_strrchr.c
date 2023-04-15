/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:22:03 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/27 20:24:31 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*tmp;
	char	ch;

	tmp = NULL;
	ch = c;
	while (*src != '\0')
	{
		if (*src == ch)
			tmp = (char *)src;
		src++;
	}
	if (!c)
		return ((char *)src);
	return (tmp);
}
