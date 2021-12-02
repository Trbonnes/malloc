#include "../includes/malloc.h"

void *malloc(size_t size) {
    void *ret;
    t_page *page;
    t_block *block;


    if (size < 0)
        return NULL;

    if (!g_page_head) {
        g_page_head = allocateNewPage(size);
        page = g_page_head;
    }
    else
        page = findAvailablePage(size);

    block = findAvailableBlock(page, size);
    ret = BLOCK_SHIFT_FORWARD(block, sizeof(t_block));
    ft_memset(ret, 0xaa, size);

    return ret;
}