/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:03:02 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/12 19:05:20 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_strings.h"

static size_t	size_str(char *src, t_format *f)
{
	int	n;

	n = ft_strlen(src);
	if (n >= f->width && n >= f->precision)
		return (n);
	else if (f->width > f->precision)
		return (f->width);
	return (f->precision);
}

static void	write_flags(char *arg, char *src, t_format *f, int *i)
{
	int	j;

	j = 0;
	if (f->precision >= 0 && f->precision < str_len(arg))
		while (j++ < f->width - f->precision)
			src[(*i)++] = ' ';
	else if (str_len(arg) < f->width)
		while (j++ < f->width - str_len(arg))
			src[(*i)++] = ' ';
}

static void	write_param(char *arg, char *src, t_format *f, int *i)
{
	int	j;

	j = 0;
	if (f->precision >= 0 && f->precision < str_len(arg))
		while ((j < f->precision && arg[j]))
			src[(*i)++] = arg[j++];
	else
		while (arg[j])
			src[(*i)++] = arg[j++];
}

static char	*null_argument(t_format *f)
{
	if (f->precision < 0 || f->precision >= 6)
		return ("(null)");
	return ("");
}

int	handle_string(va_list arg, t_format *f)
{
	char	*src_arg;
	char	*src;
	int		i;

	src_arg = va_arg(arg, char *);
	if (src_arg == NULL)
		src_arg = null_argument(f);
	src = malloc(size_str(src_arg, f) + 1);
	if (src == NULL)
		return (0);
	i = 0;
	if (MINUS_F & f->flags)
	{
		write_param(src_arg, src, f, &i);
		write_flags(src_arg, src, f, &i);
	}
	else
	{
		write_flags(src_arg, src, f, &i);
		write_param(src_arg, src, f, &i);
	}
	src[i] = '\0';
	return (return_free(src));
}