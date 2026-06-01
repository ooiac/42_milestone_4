/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 00:00:00 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 14:40:42 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*gnl_join_and_free(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		res = ft_strdup(s2);
	else
		res = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (res);
}

static char	*gnl_read_append(int fd, char *backup)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && (!backup || !ft_strchr(backup, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		buf[bytes] = '\0';
		backup = gnl_join_and_free(backup, buf);
		if (!backup)
		{
			free(buf);
			return (NULL);
		}
	}
	return (free(buf), (backup));
}

static char	*gnl_extract_line(char *backup)
{
	size_t	index;
	char	*line;

	index = 0;
	if (!backup || !*backup)
		return (NULL);
	while (backup[index] && backup[index] != '\n')
		index++;
	if (backup[index] == '\n')
		index++;
	line = ft_substr(backup, 0, index);
	return (line);
}

static char	*gnl_new_backup(char *backup)
{
	size_t	index;
	char	*new_backup;

	index = 0;
	if (!backup)
		return (NULL);
	while (backup[index] && backup[index] != '\n')
		index++;
	if (!backup[index])
	{
		free(backup);
		return (NULL);
	}
	new_backup = ft_strdup(backup + index + 1);
	free(backup);
	if (new_backup && !*new_backup)
	{
		free(new_backup);
		return (NULL);
	}
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = gnl_read_append(fd, backup);
	if (!backup)
		return (NULL);
	line = gnl_extract_line(backup);
	backup = gnl_new_backup(backup);
	if (!line && backup)
	{
		free(backup);
		backup = NULL;
	}
	return (line);
}
