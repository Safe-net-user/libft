/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:00:09 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 15:00:20 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_step_2(const char *str, int *i, int sign)
{
	int	count;
	int	j;

	count = 0;
	j = *i;
	while (str[j] && (str[j] >= '0' && str[j] <= '9'))
	{
		count *= 10;
		count += str[j] - 48;
		j++;
	}
	if (sign < 0)
		return (-count);
	return (count);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == 32)
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			return (ft_atoi_step_2(str, &i, sign));
		else if (str[i] == '-' || str[i] == '+')
		{
			sign = 43 - str[i];
			i++;
			return (ft_atoi_step_2(str, &i, sign));
		}
		else
			return (0);
	}
	return (0);
}
