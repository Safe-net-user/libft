/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:57:02 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 23:36:11 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_el;
	void	*new_content;

	if (!del || !f || !lst)
		return (NULL);
	n_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		n_el = ft_lstnew(new_content);
		if (n_el == NULL)
		{
			del(new_content);
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, n_el);
		lst = lst->next;
	}
	return (n_list);
}
