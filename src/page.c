#include "malloc.h"

static rlim_t getDataLimit(void) {
	struct rlimit rlimit;

	if (getrlimit(RLIMIT_DATA, &rlimit) < 0)
		return (-1);

	return (rlimit.rlim_max);
}

size_t findMaxDefragSize(t_page *page) {
    return 0;
}

t_pageType getPageType(size_t size) {
    if (size <= (size_t)TINY_BLOCK_SIZE)
		return (TINY);
	else if (size <= (size_t)SMALL_BLOCK_SIZE)
		return (SMALL);
	return (LARGE);
}

size_t getPageSize(size_t size) {

    t_pageType type = getPageType(size);

    if (type == TINY)
		return ((size_t)TINY_ALLOCATION_SIZE);
	else if (type == SMALL)
		return ((size_t)SMALL_ALLOCATION_SIZE);
	return (size + sizeof(t_page) + sizeof(t_block));

}

void* allocateNewPage(size_t size) {
    t_page *page;
    size_t pageSize = getPageSize(size);

    if (pageSize > getDataLimit())
        return NULL;

    page = (t_page *)mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (page == MAP_FAILED)
        return NULL;
    page->type = getPageType(size);
    page->totalSize = pageSize;
    page->availableSize = pageSize - sizeof(t_page) - sizeof(t_block);
    page->maxDefragSize = pageSize - sizeof(t_page) - sizeof(t_block);
    page->blockCount = 1;

    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));
    block->dataSize = page->maxDefragSize;
    block->freed = TRUE;

    page->next = NULL;
    if (!g_page_head)
        page->prev = NULL;
    else {
        t_page *tmp = g_page_head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = page;
        page->prev = tmp;
    }

    return (page);
}

void* findAvailablePage(size_t size) {
    t_page *page = g_page_head;
    
    while (page && size < page->maxDefragSize) { page = page->next; }

    return page ? page : allocateNewPage(size);  
}