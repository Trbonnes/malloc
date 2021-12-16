#include "malloc.h"

static rlim_t getDataLimit(void) {
	struct rlimit rlimit;

	if (getrlimit(RLIMIT_DATA, &rlimit) < 0)
		return (-1);

	return (rlimit.rlim_max);
}

t_page  *getLastPage()
{
	if (!(t_page *)g_page_head)
		return (NULL);

    t_page *page = g_page_head;
	while (page->next)
		page = page->next;

	return page;
}

t_bool isLastPage(t_pageType type) {

    t_page *page = g_page_head;
    size_t count = 0;

    while (page) {
        if (page->type == type)
            count++;
        if (count >= 2)
            return FALSE;
        page = page->next;
    }
    
    return TRUE;
}

t_bool toRemove(t_pageType type, size_t pageSize, size_t blockSize) {

    if (pageSize == blockSize && (type == LARGE || isLastPage(type) == FALSE))
        return TRUE;
    
    return FALSE;
}

void removeEmptyPage(t_page *page) {
    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));

    if (toRemove(page->type,
    page->totalSize,
    block->dataSize + sizeof(t_page) + sizeof(t_block)
    ) == FALSE) {
        return ;
    }

	if (page->next) {
		page->next->prev = page->prev;
    }
	if (page->prev) {
		page->prev->next = page->next;
    }
    else {
        g_page_head = page->next;
    }
	munmap(page, page->totalSize);
}

void defragPage(t_page *page) {

    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));
    t_block *next = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);
    size_t exploredSize = sizeof(t_page) + sizeof(t_block) + block->dataSize;

    while (exploredSize < page->totalSize) {
        exploredSize += sizeof(t_block) + next->dataSize;
        if (block->freed == TRUE && next->freed == TRUE) {
            block->dataSize += sizeof(t_block) + next->dataSize;
            page->blockCount--;
            next = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);
        }
        else if (exploredSize < page->totalSize) {
            block = next;
            next = BLOCK_SHIFT_FORWARD(next, sizeof(t_block) + block->dataSize);
        }
    }
    page->maxDefragSize = findMaxDefragSize(page);
}

size_t findMaxDefragSize(t_page *page) {
    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));
    size_t defragSize = 0;

    for (size_t i = 0; i < page->blockCount; i++) {

        if (block->freed == TRUE && block->dataSize > defragSize) 
                defragSize = block->dataSize;
        block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);
    }
    return defragSize;
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
    if (!(t_page *)g_page_head)
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
    t_pageType type = getPageType(size);
    
    if (type == LARGE)
        return allocateNewPage(size);

    while (page) {
        if (page->type == type && size < page->maxDefragSize)
            break ;
        page = page->next;
    }

    return page ? page : allocateNewPage(size);  
}