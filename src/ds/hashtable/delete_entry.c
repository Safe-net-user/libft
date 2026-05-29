#include <stddef.h>
#include "ft_hashtable.h"
#include "ft_memory.h"
#include "ft_strings.h"
#include "ft_crypto.h"

t_val   delete_value(t_ht *ht, unsigned char *key)
{
    size_t      n;
    size_t      index;

    if (ht->entries == 0)
        return (EMPTY);
    n = ft_strlen((char *)key);
    index = joaat_hash(key, n) % ht->capacity;
    while (ht->indexes[index].key != NULL)
    {
        if (ft_memcmp(ht->indexes[index].key, key, n + 1) == 0)
        {
            ht->entries--;
            ht->indexes[index].key = DELETED;
            return (SUCCESS);
        }
        index = (index + 1) % ht->capacity;
    }
    return (ERROR);
}