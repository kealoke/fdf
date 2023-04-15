/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:49:21 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/27 19:59:17 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	size_t	tlen;
	size_t	i;
	size_t	j;

	tlen = ft_strlen(target);
	if (tlen == 0)
		return ((char *)str);
	if (!str && len == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while ((target[j] == '\0' || str[i + j] == target[j]) && (i + j) <= len)
		{
			if (target[j] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
