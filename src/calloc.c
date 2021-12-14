#include "malloc.h"

void *calloc(size_t count, size_t size) {

	write(1, "calloc called\n", 14);

	void *ptr;

	if (count == 0 || size == 0) {
		count = 1;
		size = 1;
	}
	ptr = malloc(size * count);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}