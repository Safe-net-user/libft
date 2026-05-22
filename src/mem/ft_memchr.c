/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:06:02 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/13 14:51:28 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p1;
	size_t			i;

	p1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (p1[i] == (unsigned char)c)
			return (&p1[i]);
		i++;
	}
	return (NULL);
}
