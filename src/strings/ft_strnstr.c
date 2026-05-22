/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:05:13 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 16:01:01 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_bl(const char *big, const char *little, size_t i, size_t len)
{
	size_t	n;
	size_t	j;

	n = ft_strlen(little);
	j = 0;
	while (j < n)
	{
		if (big[i] != little[j] || i >= len)
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			if (check_bl(big, little, i, len) == 1)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	printf("%s", ft_strnstr("", "xx", 4294967295));
}*/
