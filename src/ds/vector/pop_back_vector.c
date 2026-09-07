#include "vector.h"

void	pop_back_vector(t_vec *v)
{
	if (!v)
		return ;
	if (v->size == 0)
		return ;
	v->curr -= v->size_element;
	v->size--;
}