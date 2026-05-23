/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:18:34 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/13 17:02:23 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
*	name:		l_t_r;
*	objective:	Write in the mem left to right
*/

static unsigned char	*l_t_r(unsigned char *p1, unsigned char *p2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (p1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) dest;
	p2 = (unsigned char *) src;
	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i-- > 0)
			p1[i] = p2[i];
	}
	else
		return (l_t_r(p1, p2, n));
	return (p1);
}
