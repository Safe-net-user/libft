/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_allocator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:26:14 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/06/09 17:26:40 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack_alloc.h"

t_stack_alloc   *init_stack_allocator(size_t n)
{
    t_stack_alloc *sa;

    if (n == 0)
        return (NULL);
    sa = malloc(sizeof(t_stack_alloc));
    if (!sa)
        return (NULL);
    sa->buffer = malloc(n);
    if (!sa->buffer) {
        free(sa);
        return (NULL);
    }
    sa->curr = NULL;
    sa->up = sa->buffer;
    sa->capacity = n;
    return (sa);
}