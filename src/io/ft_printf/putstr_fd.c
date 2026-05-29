/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:31:32 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/06 10:56:36 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_strings.h"

int	putstr_fd(char *s, int fd)
{
    if (!s)
        return (write(fd, "(null)", 6));
    return (write(fd, s, ft_strlen((const char *) s)));
}