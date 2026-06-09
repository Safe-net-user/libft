#ifndef FT_STRING_BUILDER_H
#define FT_STRING_BUILDER_H

# include <stddef.h>

typedef struct s_sb
{
        char    *str;
        size_t  lenght;
        size_t  capacity;
}       t_sb;

t_sb    *init_sb(t_sb *sb, size_t capacity);
int     append_sb(t_sb *sb, char *str);
void    free_sb(t_sb *sb);
#endif