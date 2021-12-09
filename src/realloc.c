#include "malloc.h"

void *realloc(void *ptr, size_t size) {

    printf("realloc called\n");

    if (!ptr)
		return (malloc(size));
	else if (size == 0) {
		free(ptr);
		return (NULL);
	}

    t_page *page = g_page_head;
    t_block *block;
    void *new;
    findPointer(ptr, &page, &block);
    if (page && block) {
        if (block->dataSize == size)
            return ptr;
        new = malloc(size);
        ft_memmove(new, ptr, block->dataSize > size ? size : block->dataSize);
        free(ptr);
        return new;
    }

    return NULL;
}