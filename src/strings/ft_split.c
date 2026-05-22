/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:27:18 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/14 12:00:33 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	occ_separator(char const *s, char c)
{
	unsigned int	i;
	size_t				occ;

	i = 0;
	occ = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			occ ++;
		while (s[i] != c && s[i])
			i++;
	}
	return (occ);
}

static char	*part(char const *s, size_t i, size_t *j)
{
	char	*p;
	size_t	k;

	p = malloc(i - *j + 1);
	k = 0;
	if (p == NULL)
		return (NULL);
	while (*j < i)
	{
		p[k] = s[*j];
		k++;
		(*j)++;
	}
	p[k] = '\0';
	return (p);
}

static void	*free_arr(char **p, size_t size, size_t occ)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = size;
	while (i < j && i <= occ)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static char	**final_arr(char **p, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	occ;

	i = 0;
	j = 0;
	occ = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
		{
			p[occ] = part(s, i, &j);
			if (p[occ] == NULL)
				return (free_arr(p, occ_separator(s, c) + 1, occ));
			occ++;
		}
	}
	p[occ] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc(sizeof(char *) * (occ_separator(s, c) + 1));
	if (p == NULL)
		return (NULL);
	return (final_arr(p, s, c));
}
