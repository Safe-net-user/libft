/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:06:59 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 15:09:57 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	size(long c)
{
	if (c < 10)
		return (1);
	else if (c < 100)
		return (2);
	else if (c < 1000)
		return (3);
	else if (c < 10000)
		return (4);
	else if (c < 100000)
		return (5);
	else if (c < 1000000)
		return (6);
	else if (c < 10000000)
		return (7);
	else if (c < 100000000)
		return (8);
	else if (c < 1000000000)
		return (9);
	return (10);
}

static char	*int_to_ascii(char *src, long n, int i)
{
	if (n >= 10)
		int_to_ascii(src, n / 10, i - 1);
	src[i] = (char)((n % 10) + '0');
	return (src);
}

char	*ft_itoa(int nb)
{
	int	sign;
	char	*p;
	long	n;

	sign = 0;
	n = nb;
	if (n < 0)
	{
		sign ++;
		n = -n;
	}
	p = malloc((size_t)(size(n) + sign + 1));
	if (p == NULL)
		return (NULL);
	if (sign == 1)
		p[0] = '-';
	int_to_ascii(p + sign, n, size(n) - 1);
	p[size(n) + sign] = '\0';
	return (p);
}
