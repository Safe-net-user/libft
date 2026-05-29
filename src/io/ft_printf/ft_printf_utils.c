/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:23:35 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/08 16:31:22 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_present(char *lst, char c)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		if (lst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

bool	is_format_valid(const char *format, int i)
{
	i++;
	while (is_present(" 0+-#", format[i]))
		i++;
	if (is_present("dixXupcs%", format[i]))
		return (1);
	while (is_present("0123456789", format[i]))
		i++;
	if (is_present("dixXupcs%", format[i]))
		return (1);
	if (format[i++] == '.')
	{
		while (is_present("0123456789", format[i]))
			i++;
		if (is_present("dixXupcs%", format[i]))
			return (1);
	}
	return (0);
}

int	return_free(char *src)
{
	int	count;

	count = putstr_fd(src, STDOUT);
	free(src);
	return (count);
}

int	size(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

int	len_string(int nb, t_format *f)
{
	int	sign;

	sign = 0;
	if ((size(nb) >= 0 && (PLUS_F & f->flags || SPACE_F & f->flags)) || nb < 0)
		sign = 1;
	if (size(nb) >= f->precision && size(nb) >= f->width)
		return (size(nb) + sign + 1);
	else if (f->precision < f->width)
		return (f->width + 1);
	return (f->precision + sign + 1);
}