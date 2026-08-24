/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiaudfiz <fiaudfiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:43:53 by fiaudfiz          #+#    #+#             */
/*   Updated: 2026/08/24 15:45:26 by fiaudfiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <errno.h>
#include "ft_strings.h"

int	gnl_check_empty(char **buf)
{
	if (!*buf || !(*buf)[0])
	{
		free(*buf);
		*buf = NULL;
		return (1);
	}
	return (0);
}

void	gnl_reset(void)
{
	gnl(-1, NULL);
}
