/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:59:32 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/06/30 12:28:15 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	int_to_ascii(char *src, unsigned int nb, int i)
{
	if (nb >= 10)
		int_to_ascii(src, nb / 10, i - 1);
	src[i] = (char)(nb % 10) + '0';
}

static void	write_flags(t_format *f, unsigned int nb, char *src, int *i)
{
	int	j;

	j = 0;
	if (f->precision == 0 && nb == 0)
		j--;
	if (size_u(nb) >= f->width || f->precision >= f->width)
		return ;
	if (ZERO_F & f->flags && f->precision == -1 && !(MINUS_F & f->flags))
		while (j++ < (f->width - size_u(nb)))
			src[(*i)++] = '0';
	else if (f->width > f->precision && f->precision > size_u(nb))
		while (j++ < (f->width - f->precision))
			src[(*i)++] = ' ';
	else
		while (j++ < (f->width - size_u(nb)))
			src[(*i)++] = ' ';
}

static void	write_param(t_format *f, unsigned int nb, char *src, int *i)
{
	int	j;

	j = 0;
	if (size_u(nb) < f->precision)
		while (j++ < (f->precision - size_u(nb)))
			src[(*i)++] = '0';
	if (nb == 0 && f->width == 1 && f->precision == 0)
		src[(*i)++] = ' ';
	if ((nb == 0 && f->precision != 0) || nb != 0)
	{
		int_to_ascii(src, nb, *i + size_u(nb) - 1);
		(*i) += size_u(nb);
	}
}

int	handle_unsigned_int(va_list argptr, t_format *f)
{
	unsigned int	arg;
	char			*str;
	int				i;

	arg = va_arg(argptr, unsigned int);
	str = malloc((size_t)len_str_u(arg, f) + 1);
	i = 0;
	if (!str)
		return (0);
	if (MINUS_F & f->flags)
	{
		write_param(f, arg, str, &i);
		write_flags(f, arg, str, &i);
	}
	else
	{
		write_flags(f, arg, str, &i);
		write_param(f, arg, str, &i);
	}
	str[i] = '\0';
	return (return_free(str));
}