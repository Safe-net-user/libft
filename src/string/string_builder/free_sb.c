/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 11:26:37 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 11:26:47 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string_builder.h"

void	free_sb(t_sb *sb)
{
	if (!sb)
		return ;
	if (sb->str)
		free(sb->str);
	free(sb);
	sb = NULL;
}
