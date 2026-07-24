/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:03:42 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:48:17 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_nb(unsigned long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	len_str(unsigned long nb, t_format *f)
{
	int	content_len;

	if (nb == 0)
		content_len = 5;
	else
		content_len = size_nb(nb) + 2;
	if (content_len > f->width)
		return (content_len);
	return (f->width);
}

void	u_long_to_ascii(char *base, char *src, unsigned long n, int i)
{
	if (n >= 16)
		u_long_to_ascii(base, src, n / 16, i - 1);
	src[i] = (base[n % 16]);
}
