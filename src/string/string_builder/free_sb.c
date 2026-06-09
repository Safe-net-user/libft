#include <stdlib.h>
#include "ft_string_builder.h"

void    free_sb(t_sb *sb)
{
    if (!sb)
        return ;
    if (sb->str)
        free(sb->str);
    free(sb);
}