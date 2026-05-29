#ifndef FT_HASHTABLE_H
#define FT_HASHTABLE_H

#include <stdint.h>
#include <stdlib.h>

# define DELETED ((void *)-1)

typedef struct s_entry
{
       char    *key;
       char    *value;
} t_entry;

typedef struct s_ht
{
       t_entry     *indexes;
       size_t      capacity;
       size_t      entries;
}      t_ht;

typedef enum e_val
{
       ERROR,
       SUCCESS,
       EMPTY,
       FULL,
       INVALID_INDEX,
} t_val;

char *get_pointer(t_ht *ht, unsigned char *str);
t_ht    *init_hash_table(size_t n);
t_val   delete_entry(t_ht *ht, unsigned char *str);
t_val   set_new_value(t_ht *ht, char *key, unsigned char *str);

#endif
