#include "../includes/malloc.h"

void *malloc(size_t size) {
    void *ret;

    if (size < 0)
        return NULL;

    if (!g_page_head)
        g_page_head = allocateNewPage(size)

    

    return ret;
}