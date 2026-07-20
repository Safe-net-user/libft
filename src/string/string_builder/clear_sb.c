#include "ft_string_builder.h"

void    clear_sb(t_sb *sb)
{
    if (!sb)
        return ;
    sb->lenght = 0;
    sb->str[0] = '\0';
}