#include <stdint.h>
#include <stdlib.h>
#include "ft_string_builder.h"
#include "ft_memory.h"
#include "ft_strings.h"

static int extend_sb(t_sb *sb, size_t size_new_str)
{
    char    *str;

    str = malloc(sb->lenght + size_new_str + 1);
    if (!str)
        return (0);
    ft_memcpy(str, sb->str, sb->lenght);
    free(sb->str);
    sb->str = str;
    sb->capacity = sb->lenght + size_new_str + 1;
    return (1);
}

int append_sb(t_sb *sb, char *str)
{
    size_t  n;
    size_t  pre_i;
    size_t  final_i;
    size_t  index;

    if (!sb || !str)
        return (0);
    n = ft_strlen(str);
    index = 0;
    pre_i = sb->lenght;
    if (n > SIZE_MAX - pre_i)
        return (0);
    if (n + pre_i >= sb->capacity)
        if (extend_sb(sb, n) == 0)
            return (0);
    final_i = pre_i + n;
    while (pre_i < final_i)
    {
        sb->str[pre_i++] = str[index++];
        sb->lenght++;
    }
    sb->str[pre_i] = '\0';
    return (1);
}