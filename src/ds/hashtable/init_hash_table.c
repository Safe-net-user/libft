/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:37:08 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:37:55 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"
#include "ft_stdlib.h"

t_ht	*init_hash_table(size_t n)
{
	t_ht	*ht;

	if (n == 0 || n > SIZE_MAX / sizeof(t_entry))
		return (NULL);
	ht = ft_calloc(1, sizeof(*ht));
	if (!ht)
		return (NULL);
	ht->indexes = ft_calloc(n, sizeof(t_entry));
	if (!ht->indexes)
	{
		free(ht);
		return (NULL);
	}
	ht->entries = 0;
	ht->capacity = n;
	return (ht);
}
