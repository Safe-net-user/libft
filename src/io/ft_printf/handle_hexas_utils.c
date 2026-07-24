/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexas_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:53:54 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:46:15 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_h(unsigned int arg)
{
	int	i;

	i = 0;
	while (arg >= 16)
	{
		arg = arg / 16;
		i++;
	}
	return (i + 1);
}

int	size_u(unsigned int arg)
{
	int	i;

	i = 0;
	while (arg >= 10)
	{
		arg /= 10;
		i++;
	}
	return (i + 1);
}

int	len_str_h(unsigned int arg, t_format *f)
{
	if (size_h(arg) >= f->width && size_h(arg) >= f->precision)
		return (size_h(arg));
	else if (f->width > f->precision)
		return (f->width);
	return (f->precision);
}

int	len_str_u(unsigned int arg, t_format *f)
{
	if (size_u(arg) >= f->width && size_u(arg) >= f->precision)
		return (size_u(arg));
	else if (f->width > f->precision)
		return (f->width);
	return (f->precision);
}
