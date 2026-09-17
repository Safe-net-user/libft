#include "vector.h"
#include "ft_memory.h"
#include "ft_stdlib.h"
#include<stddef.h>

#include "../../../include/vector.h"

void	push_back_vector(t_vec *v, void *x)
{
	size_t	new_capacity;

	if (!v || !x)
		return ;
	if (v->capacity == 0)
		v->capacity = 1;
	if (v->capacity == v->size)
	{
		new_capacity = v->capacity * 3 / 2;
		v->buffer = ft_realloc(v->buffer, v->capacity * v->size_element, new_capacity * v->size_element);
		if (!v->buffer)
		{
			free_vector(v);
			return ;
		}
		v->curr = (char *)v->buffer + v->size * v->size_element;
		v->capacity = new_capacity;
	}
	ft_memcpy(v->curr, x, v->size_element);
	v->curr = (char *)v->curr + v->size_element;
	v->size++;
}
