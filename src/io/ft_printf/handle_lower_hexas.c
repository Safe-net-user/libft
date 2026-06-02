/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lower_hexas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 07:41:36 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/14 18:49:29 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	int_to_ascii(const char *base, char *src, unsigned int n, int i)
{
	if (n >= 16)
		int_to_ascii(base, src, n / 16, i - 1);
	src[i] = (base[n % 16]);
}

static void	write_flags(unsigned int nb, char *src, t_format *f, int *i)
{
	int	j;

	j = 0;
	if (HASHTAG_F & f->flags && nb != 0)
		j = 2;
	if ((size_h(nb) >= f->width && size_h(nb) >= f->precision)
		|| f->precision >= f->width)
		return ;
	else if (f->precision < 0 && !(MINUS_F & f->flags) && (ZERO_F & f->flags))
		while (j++ < (f->width - size_h(nb)))
			src[(*i)++] = '0';
	else if (f->width > f->precision && f->precision > size_h(nb))
		while (j++ < (f->width - (size_h(nb) + (f->precision - size_h(nb)))))
			src[(*i)++] = ' ';
	else
	{
		while (j++ < (f->width - size_h(nb)))
			src[(*i)++] = ' ';
		if (f->precision == 0 && nb == 0)
			src[(*i)++] = ' ';
	}
}

static void	write_param(unsigned int nb, char *src, t_format *f, int *i)
{
	int	j;

	j = 0;
	if (HASHTAG_F & f->flags && nb != 0)
	{
		src[(*i)++] = '0';
		src[(*i)++] = 'x';
		j += 2;
	}
	if (f->width > size_h(nb) && f->precision == -1 && !(MINUS_F & f->flags)
		&& ZERO_F & f->flags && HASHTAG_F & f->flags)
		while (j++ < (f->width - size_h(nb)))
			src[(*i)++] = '0';
	j = 0;
	if (f->precision > size_h(nb))
		while (j++ < (f->precision - size_h(nb)))
			src[(*i)++] = '0';
	if (nb == 0 && f->width == 1 && f->precision == 0)
		src[(*i)++] = ' ';
	if ((nb == 0 && f->precision != 0) || nb != 0)
	{
		int_to_ascii("0123456789abcdef", src, nb, *i + size_h(nb) - 1);
		(*i) += size_h(nb);
	}
}

int	handle_lower_hexas(va_list argptr, t_format *f)
{
	unsigned int	arg;
	char			*p;
	int				i;
	int				prefix;

	arg = va_arg(argptr, unsigned int);
	i = 0;
	prefix = 0;
	if (HASHTAG_F & f->flags && arg != 0)
		prefix = 2;
	p = malloc((size_t)len_str_h(arg, f) + (size_t)prefix + 1);
	if (p == NULL)
		return (0);
	if (MINUS_F & f->flags)
	{
		write_param(arg, p, f, &i);
		write_flags(arg, p, f, &i);
	}
	else
	{
		write_flags(arg, p, f, &i);
		write_param(arg, p, f, &i);
	}
	p[i] = '\0';
	return (return_free(p));
}