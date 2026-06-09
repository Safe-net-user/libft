#include "ft_hashtable.h"
#include "ft_strings.h"
#include "ft_crypto.h"

t_val   set_new_value(t_ht *ht, char *key, char *str)
{
    size_t      n;
    size_t      index;

    if (ht->entries == ht->capacity)
        return (FULL);
    n = ft_strlen(key);
    index = joaat_hash((unsigned char *)key, n) % ht->capacity;
    while (ht->indexes[index].key != NULL)
    {
        if (ft_strncmp(ht->indexes[index].key, key, n) == 0)
            return (ERROR);
        index = (index + 1) % ht->capacity;
    }
    ht->indexes[index].value = ft_strdup(str);
    ht->indexes[index].key = ft_strdup(key);
    ht->entries++;
    return (SUCCESS);
}