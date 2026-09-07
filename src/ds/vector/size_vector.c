# include "vector.h"

size_t	size_vector(t_vec *v)
{
	if (!v)
		return (0);
	return (v->size);
}