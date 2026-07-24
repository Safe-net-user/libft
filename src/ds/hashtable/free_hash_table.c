/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:34:58 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:39:44 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_hashtable.h"

void	free_hash_table(t_ht *ht)
{
	size_t	i;

	i = 0;
	if (!ht)
		return ;
	while (i < ht->capacity)
	{
		if (ht->indexes[i].key != NULL && ht->indexes[i].key != DELETED)
		{
			free(ht->indexes[i].value);
			free(ht->indexes[i].key);
		}
		i++;
	}
	free(ht->indexes);
	free(ht);
}
