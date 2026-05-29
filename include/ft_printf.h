/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:28:09 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/01/12 19:03:42 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_format
{
	unsigned char	c;
	int				flags;
	int				width;
	int				precision;
}	t_format;

typedef int	(*t_funct)(va_list ap, t_format *f);

enum e_flags
{
	SPACE_F = 1 << 0,
	PLUS_F = 1 << 1,
	HASHTAG_F = 1 << 2,
	MINUS_F = 1 << 3,
	ZERO_F = 1 << 4,
};

/* main function */
int			ft_printf(const char *format, ...);

/* parsing function */
t_format	*format_parsing(const char *format, int *i);

/* handle functions */
int			handle_int(va_list nb, t_format *f);
int			handle_string(va_list src, t_format *f);
int			handle_lower_hexas(va_list nb, t_format *f);
int			handle_upper_hexas(va_list nb, t_format *f);
int			handle_unsigned_int(va_list nb, t_format *f);
int			handle_pointer(va_list nb, t_format *f);
int			handle_char(va_list c, t_format *f);
int			handle_percent(va_list c, t_format *f);

/* functions for hexas and unsigned type functions*/
int			size_u(unsigned int nb);
int			len_str_u(unsigned int nb, t_format *f);
int			size_h(unsigned int nb);
int			len_str_h(unsigned int nb, t_format *f);

/* handle_pointer_utils functions */
int			size_nb(unsigned long nb);
int			len_str(unsigned long nb, t_format *f);
void		u_long_to_ascii(char *base, char *src, unsigned long n, int i);

/* printf_utils functions */
bool		is_format_valid(const char *format, int i);
int			return_free(char *src);
bool		is_present(char *lst, char c);
int			size(long nb);
int			len_string(int nb, t_format *f);

/* file descriptor writer functions */
int			putchar_fd(char c, int fd);
int			putstr_fd(char *src, int fd);

/* str_len functions for an integer returnment */
int			str_len(char *src);
#endif
