/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:45:18 by miouali           #+#    #+#             */
/*   Updated: 2026/08/20 11:46:32 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*gnl(int fd, int *interrupted);
char	*ft_strjoin_free(char *s1, char *s2);
int		line_matches_delim(char *line, char *lim);
void	gnl_reset(void);
char	*ft_strjoin_free(char *s1, char *s2);
int	line_matches_delim(char *line, char *lim);
char    *gnl_strchr(const char *s, int c);

#endif