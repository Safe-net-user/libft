#include "vector.h"
#include <stdlib.h>

void	free_vector(t_vec *v)
{
	free(v->buffer);
	free(v);
}
