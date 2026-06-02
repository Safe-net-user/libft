/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:52:50 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/14 18:46:48 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	int_to_ascii(char *src, long nb, int i)
{
	if (nb >= 10)
		int_to_ascii(src, nb / 10, i - 1);
	src[i] = (nb % 10) + '0';
}

static void	write_sign(t_format *f, int nb, char *src, int *i)
{
	if (nb < 0)
		src[(*i)++] = '-';
	else if (nb >= 0 && SPACE_F & f->flags && !(PLUS_F & f->flags))
		src[(*i)++] = ' ';
	else if (nb >= 0 && PLUS_F & f->flags)
		src[(*i)++] = '+';
}

static void	write_flags(t_format *f, int nb, char *src, int *i)
{
	int	j;

	j = 0;
	if ((nb >= 0 && (SPACE_F & f->flags || PLUS_F & f->flags)) || nb < 0)
		j++;
	if ((size(nb) >= f->width && size(nb) >= f->precision)
		|| (f->precision >= f->width && f->precision >= size(nb)))
		return ;
	else if (ZERO_F & f->flags && f->precision == -1 && !(MINUS_F & f->flags))
	{
		write_sign(f, nb, src, i);
		while (j++ < (f->width - size(nb)))
			src[(*i)++] = '0';
	}
	else if (f->precision < size(nb))
	{
		while (j++ < (f->width - size(nb)))
			src[(*i)++] = ' ';
		if (f->precision == 0 && nb == 0)
			src[(*i)++] = ' ';
	}
	else
		while (j++ < (f->width - (size(nb) + (f->precision - size(nb)))))
			src[(*i)++] = ' ';
}

static void	write_param(t_format *f, int nb, char *src, int *i)
{
	int		j;
	long	n;

	j = 0;
	n = nb;
	if ((!(ZERO_F & f->flags) || f->precision != -1 || (size(nb) >= f->width
				&& size(nb) >= f->precision) || (f->precision >= f->width
				&& f->precision >= size(nb))) && !(MINUS_F & f->flags))
		write_sign(f, nb, src, i);
	if (n < 0)
		n = -n;
	if (size(n) < f->precision)
		while (j++ < (f->precision - size(nb)))
			src[(*i)++] = '0';
	if (n == 0 && f->width == 1 && f->precision == 0)
		src[(*i)++] = ' ';
	if ((n == 0 && f->precision != 0) || n != 0)
	{
		int_to_ascii(src, n, *i + size(nb) - 1);
		(*i) += size(nb);
	}
}

int	handle_int(va_list argptr, t_format *f)
{
	int		nb;
	char	*str;
	int		i;

	nb = va_arg(argptr, int);
	str = malloc((size_t)len_string(nb, f));
	i = 0;
	if (!str)
		return (0);
	if (MINUS_F & f->flags)
	{
		write_sign(f, nb, str, &i);
		write_param(f, nb, str, &i);
		write_flags(f, nb, str, &i);
		str[i] = '\0';
		return (return_free(str));
	}
	write_flags(f, nb, str, &i);
	write_param(f, nb, str, &i);
	str[i] = '\0';
	return (return_free(str));
}