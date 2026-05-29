#include "ft_hashtable.h"
#include "ft_stdlib.h"

t_ht    *init_hash_table(size_t n)
{
    t_ht    *ht;

    if (n == 0 || n > SIZE_MAX / sizeof(char *))
        return (NULL);
    ht = ft_calloc(1, sizeof(*ht));
    if (!ht)
        return (NULL);
    ht->indexes = ft_calloc(n, sizeof(t_entry *));
    if (!ht->indexes)
    {
        free(ht);
        return (NULL);
    }
    ht->entries = 0;
    ht->capacity = n;
    return (ht);
}