#include "malloc.h"

t_page *g_page_head = NULL;

void *malloc(size_t size) {

    // write(1, "\nmalloc called : ", 17);
    // ft_putnbr_fd(size, 1);
    // show_alloc_mem();

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

    // ft_putstr_fd("\npage found\n", 1);
    // printPointer((size_t)page, 9);
    // ft_putstr_fd(" - ", 1);
    // ft_putnbr_fd(page->maxDefragSize, 1);
    // ft_putstr_fd(" bytes available\n", 1);

    block = findAvailableBlock(page, size);
    // ft_putstr_fd("block found\n", 1);
    // printPointer((size_t)block, 9);
    ret = BLOCK_SHIFT_FORWARD(block, sizeof(t_block));
    ft_memset(ret, 0xaa, size);
    // ft_putstr_fd("\nreturning pointer\n", 1);
    // printPointer((size_t)ret, 9);
    // ft_putstr_fd("\n", 1);

    // show_alloc_mem();

    return ret;
}