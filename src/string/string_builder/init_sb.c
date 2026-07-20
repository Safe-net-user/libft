#include <stdlib.h>
#include "ft_string_builder.h"

t_sb    *init_sb(size_t capacity)
{
    t_sb    *sb;
    
    sb = malloc(sizeof *sb);
    if (!sb)
        return (NULL);
    sb->str = malloc(capacity);
    sb->str[0] = '\0';
    if (!sb->str)
    {
        free(sb);
        return (NULL);
    }
    sb->lenght = 0;
    sb->capacity = capacity;
    return (sb);
}