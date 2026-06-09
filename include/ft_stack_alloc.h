#ifndef FT_STACK_ALLOC_H
#define FT_STACK_ALLOC_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

#define ALIGNMENT 8

typedef struct s_header
{
    size_t  size;
    size_t  prev_size;
}   t_header;

typedef  struct s_stack_alloc
{
    void  *buffer;
    void  *up;
    void  *curr;
    size_t  capacity;
}   t_stack_alloc;

t_stack_alloc   *init_stack_allocator(size_t n);
void   stack_dealloc(t_stack_alloc *sa);
void   *stack_alloc(t_stack_alloc *sa, size_t size);

#endif