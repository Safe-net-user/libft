#include <stddef.h>

#include "ft_hashtable.h"

void    free_hash_table(t_ht *ht)
{
    size_t  i;

    i = 0;
    while (i < ht->capacity)
    {
        if (ht->indexes[i].key != NULL  && ht->indexes[i].key != DELETED)
        {
            free(ht->indexes[i].value);
            free(ht->indexes[i].key);
        }
        i++;
    }
    free(ht->indexes);
    free(ht);
    ht = NULL;
}
