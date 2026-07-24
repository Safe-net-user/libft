/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ch_sb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:30:46 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 11:30:03 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_string_builder.h"
#include "ft_memory.h"
#include "ft_strings.h"

static int	extend_sb(t_sb *sb, size_t size_new_str)
{
	char	*str;

	str = malloc(sb->lenght + size_new_str + 1);
	if (!str)
		return (0);
	ft_memcpy(str, sb->str, sb->lenght);
	free(sb->str);
	sb->str = str;
	sb->capacity = sb->lenght + size_new_str + 1;
	return (1);
}

int	append_ch_sb(t_sb *sb, char c)
{
	size_t	n;
	size_t	pre_i;

	if (!sb || !c)
		return (0);
	n = 1;
	pre_i = sb->lenght;
	if (n > SIZE_MAX - pre_i)
		return (0);
	if (n + pre_i >= sb->capacity)
		if (extend_sb(sb, n) == 0)
			return (0);
	sb->str[pre_i++] = c;
	sb->lenght++;
	sb->str[pre_i] = '\0';
	return (1);
}
