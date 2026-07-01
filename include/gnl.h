/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:33:48 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/01 14:00:51 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include  <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define LC '\n'

typedef struct s_node {
        char                    *str;
        struct s_node   *next;
}       t_node;

char    *get_next_line(int fd);
void    clear_list(t_node **lst);
size_t  ft_strcpy_lc_count(char *dst, char *src, size_t n);
t_node  *create_node(char *str, size_t bytes_read);
int             add_back(char *str, t_node **lst, size_t bytes_read);
void    clear_node(t_node *node, t_node **lst);


#endif