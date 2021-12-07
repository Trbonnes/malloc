#include "malloc.h"

void *calloc(size_t count, size_t size)
{
	void *ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}