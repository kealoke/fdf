/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:36:18 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/09 14:14:15 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		save = (char *)malloc(1);
		if (!save)
			return (NULL);
		save[0] = 0;
	}
	save = read_and_save(fd, &save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = get_next_save(save);
	return (line);
}

char	*read_and_save(int fd, char **save)
{
	ssize_t	size;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free (*save);
		*save = NULL;
		return (NULL);
	}
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (ft_free_gnl(buf, *save));
		buf[size] = '\0';
		*save = ft_strjoin_gnl(*save, buf);
		if (!*save)
			return (ft_free_gnl(buf, *save));
		if (ft_strchr_gnl(buf, '\n'))
			break ;
	}
	free(buf);
	return (*save);
}

char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr_gnl(save, 0, i + 1);
	if (!line)
	{
		free (save);
		save = NULL;
		return (NULL);
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_save(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	tmp = ft_substr_gnl(save, i + 1, ft_strlen_gnl(save) - i);
	free (save);
	if (!tmp)
	{
		save = NULL;
		return (NULL);
	}
	save = tmp;
	return (save);
}

void	*ft_free_gnl(char *buf, char *save)
{
	free(buf);
	buf = NULL;
	free(save);
	save = NULL;
	return (NULL);
}
