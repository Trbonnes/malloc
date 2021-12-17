#include "malloc.h"

void *do_realloc(void *ptr, size_t size) {

    if (!ptr)
		return (do_malloc(size));
	else if (size == 0) {
		do_free(ptr);
		return (NULL);
	}

    t_page *page = g_page_head;
    t_block *block;
    void *new;
    findPointer(ptr, &page, &block);
    if (page && block) {
        if (block->dataSize == size)
            return ptr;
        new = do_malloc(size);
        ft_memcpy(new, ptr, block->dataSize > size ? size : block->dataSize);
        do_free(ptr);
        return new;
    }

    return NULL;
}

void *realloc(void *ptr, size_t size) {
    void *ret;

    pthread_mutex_lock(&g_malloc_mutex);
    ret = do_realloc(ptr, size);
    pthread_mutex_unlock(&g_malloc_mutex);

    return ret;
}