#include <stdlib.h>
#include "ft_string_builder.h"

t_sb    *init_sb(t_sb *sb, size_t capacity)
{
    sb = malloc(sizeof *sb);
    if (!sb)
        return (NULL);
    sb->str = malloc(capacity);
    if (!sb->str)
    {
        free(sb);
        return (NULL);
    }
    sb->lenght = 0;
    sb->capacity = capacity;
    return (sb);
}