/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:32:31 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 22:35:29 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void    del(void *content)
{
    free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return ;
	del(current->content);
	free(current);
}
