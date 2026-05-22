/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:20:42 by gd-hallu          #+#    #+#             */
/*   Updated: 2025/11/20 20:17:28 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int main()
{
    t_list *head = NULL;
    t_list *a1;
    t_list *a2;
    a1 = ft_lstnew("a1");
    a2 = ft_lstnew("a2");
    ft_lstadd_front(&head, a1);
    ft_lstadd_front(&head, a2);
    t_list *current = a2;
    while (current->next != NULL)
    {
        printf("%s", (char *)current->content);
        current = current->next;
    }
}*/
