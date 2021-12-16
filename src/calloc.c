#include "malloc.h"

void *do_calloc(size_t count, size_t size) {

	void *ptr;

	if (count == 0 || size == 0) {
		count = 1;
		size = 1;
	}
	ptr = do_malloc(size * count);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

void *calloc(size_t count, size_t size) {
    void *ret;

    pthread_mutex_lock(&g_malloc_mutex);
    ret = do_calloc(count, size);
    pthread_mutex_unlock(&g_malloc_mutex);

    return ret;
}