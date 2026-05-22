/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:20:27 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/13 14:52:44 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *n, int value, size_t count)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *) n;
	while (i < count)
	{
		p[i] = (char)value;
		i += 1;
	}
	return (n);
}
