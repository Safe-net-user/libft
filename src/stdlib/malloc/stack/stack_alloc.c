/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 11:15:37 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 11:16:40 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack_alloc.h"
#include <stdio.h>

void	*stack_alloc(t_stack_alloc *sa, size_t size)
{
	t_header	*h;
	t_header	*last;

	if ((size_t)((uint8_t *)sa->up - (uint8_t *)sa->buffer) + \
sizeof(*h) + size > sa->capacity)
		return (NULL);
	h = (t_header *)sa->up;
	h->size = size;
	if (!sa->curr)
		h->prev_size = 0;
	else
	{
		last = ((t_header *)sa->curr) - 1;
		h->prev_size = last->size;
	}
	sa->curr = (uint8_t *)h + sizeof(t_header);
	sa->up = (uint8_t *)sa->up + (sizeof(t_header) + size);
	return (sa->curr);
}
