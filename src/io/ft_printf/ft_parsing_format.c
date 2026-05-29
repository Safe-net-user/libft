/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 08:29:30 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/06 10:54:11 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_strings.h"
#include "ft_stdlib.h"
#include <stdlib.h>

static t_format	*init_struct(void)
{
    t_format	*f;

    f = malloc(sizeof(t_format));
    if (!f)
        return (NULL);
    f->c = 0;
    f->flags = 0;
    f->width = 0;
    f->precision = -1;
    return (f);
}

static void	handle_flags(t_format *f, int *i, const char *format)
{
    while (is_present(" +-#0", format[*i]))
    {
        if (format[*i] == ' ')
            f->flags |= SPACE_F;
        else if (format[*i] == '+')
            f->flags |= PLUS_F;
        else if (format[*i] == '#')
            f->flags |= HASHTAG_F;
        else if (format[*i] == '0')
            f->flags |= ZERO_F;
        else
            f->flags |= MINUS_F;
        (*i)++;
    }
}

t_format	*format_parsing(const char *format, int *i)
{
    t_format	*f;

    f = init_struct();
    (*i)++;
    handle_flags(f, i, format);
    f->width = ft_atoi(&format[*i]);
    while (format[*i] && is_present("0123456789", format[*i]))
        (*i)++;
    if (format[*i] == '.')
    {
        f->precision = ft_atoi(&format[++(*i)]);
        while (format[*i] && is_present("0123456789", format[*i]))
            (*i)++;
    }
    f->c = format[*i];
    return (f);
}