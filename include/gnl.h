/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:45:18 by miouali           #+#    #+#             */
/*   Updated: 2026/08/26 12:10:23 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*gnl(int fd, int *interrupted);
int		line_matches_delim(char *line, char *lim);
void	gnl_reset(void);
int		line_matches_delim(char *line, char *lim);
char	*gnl_strchr(const char *s, int c);
int		gnl_check_empty(char **buf);

#endif
