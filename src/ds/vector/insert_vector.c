#include "vector.h"
#include "ft_memory.h"

void	insert_vector(t_vec *v, size_t i, void *x)
{
	size_t	j;

	if (!v || !x || i > v->size)
		return ;
	/*if (v->size == v->capacity)
		resize_vector(v);*/
	j = v->size;
	while (j > i)
	{
		ft_memcpy(
			v->buffer + j * v->size_element,
			v->buffer + (j - 1) * v->size_element,
			v->size_element
		);
		j--;
	}
	ft_memcpy(v->buffer + i * v->size_element, x, v->size_element);
	v->size++;
}