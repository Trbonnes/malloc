#include "malloc.h"

t_page *g_page_head = NULL;

void *malloc(size_t size) {

    printf("malloc called\n");

    void *ret;
    t_page *page;
    t_block *block;

    if (!size)
        return NULL;

    size = (size + 15) & ~15; //16 bytes aligment

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