/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:50:18 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/13 14:54:57 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		occ;

	i = 0;
	occ = -1;
	if (c > 255)
		c = c % 256;
	while (s[i])
	{
		if (s[i] == c)
			occ = i;
		i++;
	}
	if (s[i] == c)
		return ((char *) &s[i]);
	if (occ == -1)
		return (NULL);
	if (s[i] == c)
		return ((char *) &s[i]);
	return ((char *) &s[occ]);
}
