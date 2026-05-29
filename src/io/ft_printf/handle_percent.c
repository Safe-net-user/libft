/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:17:15 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/12 19:10:02 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(va_list argptr, t_format *f)
{
    (void) argptr;
    (void) f;
    return (putchar_fd('%', STDOUT));
}