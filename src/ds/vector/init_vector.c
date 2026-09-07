#include "vector.h"
#include <stdint.h>
#include <stdlib.h>
t_vec	*init_vector(void *type, size_t n)
{
	t_vec	*v;

	if (n == 0 || n > SIZE_MAX / sizeof(type))
		return (NULL);
	v = malloc(sizeof(t_vec));
	if (!v)
		return (NULL);
	v->buffer = malloc(sizeof(type) * n);
	if (!v->buffer)
	{
		free(v);
		return (NULL);
	}
	v->size_element = sizeof(*type);
	v->curr = v->buffer;
	v->capacity = n;
	v->size = 0;
	return (v);
}