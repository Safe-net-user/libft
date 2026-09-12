#include "vector.h"
#include <stdint.h>
#include <stdlib.h>
t_vec	*init_vector(int size_element, size_t n)
{
	t_vec	*v;

	if (n == 0 || n > SIZE_MAX / size_element)
		return (NULL);
	v = malloc(sizeof(t_vec));
	if (!v)
		return (NULL);
	v->buffer = malloc(size_element * n);
	if (!v->buffer)
	{
		free(v);
		return (NULL);
	}
	v->size_element = size_element;
	v->curr = v->buffer;
	v->capacity = n;
	v->size = 0;
	return (v);
}