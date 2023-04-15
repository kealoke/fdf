/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:17:28 by yushimom          #+#    #+#             */
/*   Updated: 2022/11/11 15:36:15 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_count_len(const char *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (s[i] == c)
			break ;
	}
	return (len);
}

static void	*ft_free(char **res, size_t j)
{
	size_t	p;

	p = 0;
	while (p < j)
	{
		free(res[p]);
		res[p] = NULL;
		p++;
	}
	free(res);
	res = NULL;
	return (NULL);
}

static char	**get_substr(const char *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			word_len = ft_count_len(s, c, i);
			res[j] = ft_substr(s, i, word_len);
			if (res[j] == NULL)
				return (ft_free(res, j));
			j++;
			i = i + word_len;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	res = get_substr(s, c, res);
	return (res);
}
