/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:38:46 by miouali           #+#    #+#             */
/*   Updated: 2026/08/24 15:44:42 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <errno.h>
#include "ft_strings.h"

static int	fill_buffer(int fd, char **buf)
{
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!gnl_strchr(*buf, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1 && errno == EINTR)
			return (-2);
		if (bytes_read == -1)
		{
			free(*buf);
			*buf = NULL;
			return (-1);
		}
		if (bytes_read == 0)
			break ;
		read_buf[bytes_read] = '\0';
		*buf = ft_strjoin_free(*buf, read_buf);
		if (!*buf)
			return (-1);
	}
	return (0);
}

static char	*extract_line(char *buf)
{
	char	*nl;
	char	*line;
	size_t	len;
	size_t	i;

	if (!buf || !buf[0])
		return (NULL);
	nl = gnl_strchr(buf, '\n');
	if (nl)
		len = (size_t)(nl - buf) + 1;
	else
		len = ft_strlen(buf);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*extract_rest(char *buf)
{
	char	*nl;
	char	*rest;
	size_t	i;

	nl = gnl_strchr(buf, '\n');
	if (!nl)
		return (NULL);
	rest = malloc(ft_strlen(nl + 1) + 1);
	if (!rest)
		return (NULL);
	i = 0;
	while (nl[i + 1])
	{
		rest[i] = nl[i + 1];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*gnl(int fd, int *interrupted)
{
	static char	*buf = NULL;
	char		*line;
	char		*tmp;
	int			res;

	if (fd == -1)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	res = fill_buffer(fd, &buf);
	if (interrupted)
		*interrupted = (res == -2);
	if (res == -1 || res == -2)
		return (NULL);
	if (gnl_check_empty(&buf))
		return (NULL);
	line = extract_line(buf);
	tmp = buf;
	buf = extract_rest(buf);
	free(tmp);
	return (line);
}
