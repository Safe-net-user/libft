/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:38:43 by miouali           #+#    #+#             */
/*   Updated: 2026/08/20 11:44:53 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "ft_strings.h"

char    *gnl_strchr(const char *s, int c)
{
    while (s && *s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (s && (char)c == '\0')
        return ((char *)s);
    return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[len1 + i] = s2[i];
		i++;
	}
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}

int	line_matches_delim(char *line, char *lim)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (ft_strlen(lim) == len && ft_strncmp(line, lim, len) == 0);
}