/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:33:32 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 11:11:36 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	clear_list(t_node **lst)
{
	t_node	*current;
	t_node	*next;

	current = *lst;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	*lst = NULL;
}

t_node	*create_node(char *str, size_t bytes_read)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->str = malloc(bytes_read + 1);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	ft_strcpy_lc_count(new->str, str, bytes_read);
	new->str[bytes_read] = '\0';
	new->next = NULL;
	return (new);
}

int	add_back(char *str, t_node **lst, size_t bytes_read)
{
	t_node	*new;
	t_node	*curr;

	new = create_node(str, bytes_read);
	if (!new)
		return (-1);
	if (*lst == NULL)
	{
		*lst = new;
		return (1);
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (1);
}

static void	add_front(t_node *node, t_node **lst, size_t *i)
{
	size_t	j;
	t_node	*new;

	j = 0;
	while (node->str[*i + j])
		j++;
	new = create_node(node->str + *i, j);
	if (!new)
	{
		free(node->str);
		free(node);
		clear_list(lst);
		return ;
	}
	*lst = node->next;
	free(node->str);
	new->next = *lst;
	*lst = new;
	free(node);
}

void	clear_node(t_node *node, t_node **lst)
{
	size_t	i;

	i = 0;
	while (node->str[i] && node->str[i] != LC)
		i++;
	if (!node->str[i])
	{
		*lst = node->next;
		free(node->str);
		free(node);
		return ;
	}
	i++;
	add_front(node, lst, &i);
}
