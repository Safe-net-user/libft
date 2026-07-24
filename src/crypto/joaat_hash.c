/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joaat_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:22:29 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:23:21 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_crypto.h"

uint32_t	joaat_hash(unsigned char *key, size_t len)
{
	uint32_t	hash;
	size_t		i;

	hash = 0;
	i = 0;
	while (i < len)
	{
		hash += key[i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}
