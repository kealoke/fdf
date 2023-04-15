/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:02:55 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/22 21:32:41 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	sub_len;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) < start)
	{
		substr = ft_calloc(1, sizeof(char));
		return (substr);
	}
	sub_len = ft_strlen(s + start);
	if (sub_len < len)
		len = sub_len;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (*s != '\0' && len-- > 0)
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}
