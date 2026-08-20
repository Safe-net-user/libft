/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:38:46 by miouali           #+#    #+#             */
/*   Updated: 2026/08/20 11:47:19 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <errno.h>

static char	*g_buf = NULL;

static int	fill_buffer(int fd)
{
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(g_buf, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1 && errno == EINTR)
			return (-2);
		if (bytes_read == -1)
		{
			free(g_buf);
			g_buf = NULL;
			return (-1);
		}
		if (bytes_read == 0)
			break ;
		read_buf[bytes_read] = '\0';
		g_buf = ft_strjoin_free(g_buf, read_buf);
		if (!g_buf)
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
	nl = ft_strchr(buf, '\n');
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

	nl = ft_strchr(buf, '\n');
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
	char	*line;
	char	*tmp;
	int		res;

	res = hd_fill_buffer(fd);
	if (interrupted)
		*interrupted = (res == -2);
	if (res == -1 || res == -2)
		return (NULL);
	if (!g_buf || !g_buf[0])
	{
		free(g_buf);
		g_buf = NULL;
		return (NULL);
	}
	line = extract_line(g_buf);
	tmp = g_buf;
	g_buf = extract_rest(g_buf);
	free(tmp);
	return (line);
}

void	gnl_reset(void)
{
	free(g_buf);
	g_buf = NULL;
}