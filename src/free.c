#include "malloc.h"

void do_free(void *ptr) {

    if (!ptr || !(t_page *)g_page_head)
        return ;

    t_page *page = g_page_head;
    t_block *block;
    findPointer(ptr, &page, &block);
    if (page && block) {
        block->freed = TRUE;
        page->availableSize += block->dataSize;
        defragPage(page);
        removeEmptyPage(page);
    }

}

void free(void *ptr) {
    pthread_mutex_lock(&g_malloc_mutex);
    do_free(ptr);
    pthread_mutex_unlock(&g_malloc_mutex);
}