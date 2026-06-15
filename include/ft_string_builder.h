#ifndef FT_STRING_BUILDER_H
#define FT_STRING_BUILDER_H

# include <stddef.h>

typedef struct s_sb
{
        char    *str;
        size_t  lenght;
        size_t  capacity;
}       t_sb;

t_sb    *init_sb(size_t capacity);
int     append_sb(t_sb *sb, char *str);
int     append_ch_sb(t_sb *sb, char c);
void    free_sb(t_sb *sb);
#endif