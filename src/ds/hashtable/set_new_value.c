#include <stddef.h>
#include "ft_hashtable.h"
#include "ft_strings.h"
#include "ft_crypto.h"
#include <unistd.h>
#include <stdio.h>

t_val   set_new_value(t_ht *ht, char *key, unsigned char *str)
{
    size_t      n;
    size_t      index;

    if (ht->entries == ht->capacity)
        return (FULL);
    n = ft_strlen(key);
    index = joaat_hash((unsigned char *)key, n) % ht->capacity;
    while (ht->indexes[index].key != NULL)
    {
        if (ht->indexes[index].key == key)
            return (ERROR);
        index = (index + 1) % ht->capacity;
    }
    ht->indexes[index].value = (char *)str;
    ht->indexes[index].key = key;
    ht->entries++;
    return (SUCCESS);
}