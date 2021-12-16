#include "malloc.h"

t_page *g_page_head = NULL;
pthread_mutex_t g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_malloc(size_t size) {

    void *ret;
    t_page *page;
    t_block *block;

    if (!size)
        return NULL;

    size = (size + 15) & ~15; //16 bytes aligment of allocation

    if (!(t_page *)g_page_head) {
        g_page_head = allocateNewPage(size);
        page = g_page_head;
    }
    else
        page = findAvailablePage(size);

    if (!page)
        return NULL;

    block = findAvailableBlock(page, size);
    ret = BLOCK_SHIFT_FORWARD(block, sizeof(t_block));
    ft_memset(ret, 0xaa, size);

    return ret;
}

void *malloc(size_t size) {
    void *ret;

    pthread_mutex_lock(&g_malloc_mutex);
    ret = do_malloc(size);
    pthread_mutex_unlock(&g_malloc_mutex);

    return ret;
}