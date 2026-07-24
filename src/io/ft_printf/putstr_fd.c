/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:31:32 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:51:11 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_strings.h"

int	putstr_fd(char *s, int fd)
{
	if (!s)
		return ((int)(write(fd, "(null)", 6)));
	return ((int)(write(fd, s, ft_strlen((const char *) s))));
}
