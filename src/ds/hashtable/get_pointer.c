#include <stdint.h>

#include "ft_hashtable.h"
#include "ft_memory.h"
#include "ft_crypto.h"
#include "ft_strings.h"
#include <stdio.h>

#include "../../../include/ft_hashtable.h"

char *get_pointer(t_ht *ht, unsigned char *key)
{
    size_t  n;
    size_t  index;

    n = ft_strlen((char *)key);
    index = joaat_hash(key, n) % ht->capacity;
    while (ht->indexes[index].key != NULL)
    {
        if (ht->indexes[index].key != DELETED)
            if (ft_strncmp(ht->indexes[index].key, (char *)key, n + 1) == 0)
                return ht->indexes[index].value;
        index = (index + 1) % ht->capacity;
    }
    return (NULL);
}
