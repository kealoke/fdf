/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:59:35 by yushimom          #+#    #+#             */
/*   Updated: 2022/10/27 20:00:25 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_s(char str, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (str == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*get_trimmed(const char *str, size_t start, size_t end)
{
	char	*new_s;
	size_t	j;

	if (start > end)
	{
		new_s = (char *)ft_calloc(1, sizeof(char));
		return (new_s);
	}
	new_s = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	j = 0;
	while (start < end)
		new_s[j++] = str[start++];
	new_s[j] = '\0';
	return (new_s);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	slen;
	char	*new_s;

	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	if (slen == 0)
	{
		new_s = (char *)ft_calloc(1, sizeof(char));
		return (new_s);
	}
	i = 0;
	while (str[i] != '\0' && check_s(str[i], set) == 1)
		i++;
	start = i;
	while (slen > 0 && check_s(str[slen - 1], set) == 1)
		slen--;
	end = slen;
	return (get_trimmed(str, start, end));
}
