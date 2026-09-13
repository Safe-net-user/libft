#ifndef VECTOR_H
#define VECTOR_H

# include <stddef.h>

typedef struct s_vector{
	void	*buffer;
	void	*curr;
	size_t	size;
	size_t	capacity;
	size_t	size_element;

}	t_vec;

t_vec	*init_vector(int size_element, size_t n);
size_t	size_vector(t_vec *v);
void	push_back_vector(t_vec *v, void *x);
void	pop_back_vector(t_vec *v);
void	insert_vector(t_vec *v, size_t i, void *x);
void	free_vector(t_vec *v);

#endif //VECTOR_H
