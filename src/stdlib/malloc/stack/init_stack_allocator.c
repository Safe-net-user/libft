#include "ft_stack_alloc.h"

t_stack_alloc   *init_stack_allocator(t_stack_alloc *sa, size_t n)
{
    if (n == 0)
        return (NULL);
    sa->buffer = malloc(n);
    if (!sa->buffer) {
        free(sa);
        return (NULL);
    }
    sa->curr = NULL;
    sa->up = sa->buffer;
    sa->capacity = n;
    return (sa);
}