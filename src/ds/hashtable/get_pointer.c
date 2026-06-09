#include <stdint.h>

#include "ft_hashtable.h"
#include "ft_memory.h"
#include "ft_crypto.h"
#include "ft_strings.h"
#include <stdio.h>

char *get_pointer(t_ht *ht, char *key)
{
    size_t  n;
    size_t  index;

    n = ft_strlen(key);
    index = joaat_hash((unsigned char *)key, n) % ht->capacity;
    while (ht->indexes[index].key != NULL)
    {
        if (ht->indexes[index].key != DELETED)
            if (ft_strncmp(ht->indexes[index].key, key, n + 1) == 0)
                return ht->indexes[index].value;
        index = (index + 1) % ht->capacity;
    }
    return (NULL);
}
