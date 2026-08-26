/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:14:29 by miouali           #+#    #+#             */
/*   Updated: 2026/08/26 12:03:00 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_strjoin_free(char *s1, char *s2, int mode)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1 && (mode == 1 || mode == 3))
		free(s1);
	if (s2 && (mode == 2 || mode == 3))
		free(s2);
	return (res);
}
