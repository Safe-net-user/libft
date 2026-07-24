/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 11:15:02 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 11:15:29 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_stack_alloc.h"

void	stack_dealloc(t_stack_alloc *sa)
{
	t_header	*h;

	if (!sa->curr)
		return ;
	h = (t_header *)((uint8_t *)sa->curr - sizeof(*h));
	sa->up = (uint8_t *)h;
	if (h->prev_size == 0)
		sa->curr = NULL;
	else
		sa->curr = (uint8_t *)h - h->prev_size;
}
