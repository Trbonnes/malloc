#include "malloc.h"

void free(void *ptr) {

    if (!ptr || !(t_page *)g_page_head)
        return ;

    t_page *page = g_page_head;
    t_block *block;
    findPointer(ptr, &page, &block);
    if (page && block) {
        block->freed = TRUE;
        defragPage(page);
    }

    return ;
}