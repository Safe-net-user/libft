#include "vector.h"
#include "ft_memory.h"
#include "ft_stdlib.h"

void	push_back_vector(t_vec *v, void *x)
{
	if (!v || !x)
		return ;
	if (v->capacity == 0)
		v->capacity++;
	if (v->capacity == v->size)
		v->buffer = ft_realloc(v->buffer, v->capacity * v->size_element, (v->capacity * v->size_element) * 3 / 2);
	ft_memcpy(v->curr, x, v->size_element);
	v->curr += v->size_element;
	v->size++;
}