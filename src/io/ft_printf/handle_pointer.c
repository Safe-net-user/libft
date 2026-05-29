/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 00:08:17 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/06 10:55:24 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long arg)
{
	if (arg == 0)
		return (5);
	return (size_nb(arg) + 2);
}

static void	put_width(char *src, unsigned long arg, t_format *f, int *i)
{
	int	j;
	int	len;

	j = 0;
	len = ptr_len(arg);
	if (f->width <= len || (ZERO_F & f->flags && arg != 0))
		return ;
	while (j++ < f->width - len)
		src[(*i)++] = ' ';
}

static void	put_param(char *src, unsigned long arg, t_format *f, int *i)
{
	char	*nil;
	int		j;

	nil = "(nil)";
	j = 0;
	if (arg == 0)
		while (j < 5)
			src[(*i)++] = nil[j++];
	else
	{
		src[(*i)++] = '0';
		src[(*i)++] = 'x';
		if (f->width > ptr_len(arg) && ZERO_F & f->flags)
			while (j++ < f->width - ptr_len(arg))
				src[(*i)++] = '0';
		u_long_to_ascii("0123456789abcdef", src, arg, *i + size_nb(arg) - 1);
		*i += size_nb(arg);
	}
}

int	handle_pointer(va_list argptr, t_format *f)
{
	char			*src;
	int				i;
	unsigned long	arg;

	arg = va_arg(argptr, unsigned long);
	src = malloc(len_str(arg, f) + 1);
	if (!src)
		return (0);
	i = 0;
	if (MINUS_F & f->flags)
	{
		put_param(src, arg, f, &i);
		put_width(src, arg, f, &i);
	}
	else
	{
		put_width(src, arg, f, &i);
		put_param(src, arg, f, &i);
	}
	src[i] = '\0';
	return (return_free(src));
}