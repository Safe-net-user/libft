/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:05:34 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 16:00:15 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dst_s)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = ft_strlen(dst);
	i = n;
	j = 0;
	if (dst_s <= n)
		return (dst_s + ft_strlen(src));
	while (i < dst_s - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (n + ft_strlen(src));
}
