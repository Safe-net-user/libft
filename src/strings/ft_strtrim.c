/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:05:22 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 16:01:13 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static int	is_to_removed(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	index_suffixe(char const *str, char const *set)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (is_to_removed(set, str[i]) == 1 && i > 0)
		i--;
	return (i);
}

static size_t size_p(const char *str, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (0);
	while (is_to_removed(set, str[i]) == 1)
		i++;
	while (i <= index_suffixe(str, set))
	{
		j++;
		i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	j;

	p = malloc(size_p(s1, set) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		while (is_to_removed(set, s1[i]) == 1)
			i++;
		while (i <= index_suffixe(s1, set))
		{
			p[j] = s1[i];
			j++;
			i++;
		}
	}
	p[j] = '\0';
	return (p);
}

/*int main()
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *s2 = "";
	printf("%s test -> ", ft_strtrim(s1, " \t\n"));
}*/
