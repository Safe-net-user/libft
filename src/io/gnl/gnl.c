/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:33:19 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 11:07:04 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	next_segment(t_node **lst)
{
	size_t	count;
	t_node	*curr;
	size_t	i;

	curr = *lst;
	i = 0;
	count = 0;
	while (curr)
	{
		while (curr->str[i])
		{
			count++;
			if (curr->str[i++] == LC)
				return (count);
		}
		i = 0;
		curr = curr->next;
	}
	return (count);
}

size_t	ft_strcpy_lc_count(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (dst == NULL && n == 0)
	{
		while (src[i])
			if (src[i++] == LC)
				counter++;
		return (counter);
	}
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

char	*get_next_segment(t_node **lst, char *src)
{
	t_node	*curr;
	size_t	i;
	size_t	j;

	j = 0;
	while (*lst)
	{
		i = 0;
		curr = *lst;
		while (curr->str[i])
		{
			src[j++] = curr->str[i];
			if (curr->str[i++] == LC)
			{
				src[j] = '\0';
				clear_node(curr, lst);
				return (src);
			}
		}
		clear_node(curr, lst);
	}
	src[j] = '\0';
	return (src);
}

size_t	len_str(t_node **lst, int fd)
{
	char	*buff;
	ssize_t	bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (add_back(buff, lst, bytes_read) == -1)
		{
			free(buff);
			clear_list(lst);
			return (0);
		}
		if (ft_strcpy_lc_count(NULL, buff, 0) > 0)
		{
			free(buff);
			return (next_segment(lst));
		}
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (next_segment(lst));
}

char	*get_next_line(int fd)
{
	static t_node	*tab[1024];
	char			*str;
	size_t			len;

	if (fd < 0 || fd > 1024)
		return (NULL);
	len = len_str(&tab[fd], fd);
	if (len == 0)
	{
		clear_list(&tab[fd]);
		return (NULL);
	}
	str = malloc(len + 1);
	if (!str)
	{
		clear_list(&tab[fd]);
		return (NULL);
	}
	str[len] = '\0';
	return (get_next_segment(&tab[fd], str));
}
