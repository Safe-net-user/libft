/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:03:29 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/14 17:39:57 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_functions_array(t_funct *arr)
{
    arr['i'] = handle_int;
    arr['d'] = handle_int;
    arr['x'] = handle_lower_hexas;
    arr['X'] = handle_upper_hexas;
    arr['u'] = handle_unsigned_int;
    arr['p'] = handle_pointer;
    arr['c'] = handle_char;
    arr['s'] = handle_string;
    arr['%'] = handle_percent;
}

void	init_variables(int *i, int *chars_written)
{
    *i = 0;
    *chars_written = 0;
}

int	ft_printf(const char *format, ...)
{
    t_funct		arr[128];
    t_format	*f;
    int			i;
    va_list		argptr;
    int			chars_written;

    init_functions_array(arr);
    init_variables(&i, &chars_written);
    va_start(argptr, format);
    if (!format)
        return (0);
    while (format[i])
    {
        if (format[i] == '%' && is_format_valid(format, i))
        {
            f = format_parsing(format, &i);
            chars_written += arr[f->c](argptr, f);
            i++;
            free(f);
        }
        else
            chars_written += putchar_fd(format[i++], STDOUT);
    }
    va_end(argptr);
    return (chars_written);
}