#include "../includes/malloc.h"

static rlim_t getDataLimit(void) {
	struct rlimit rlimit;

	if (getrlimit(RLIMIT_DATA, &rlimit) < 0)
		return (-1);

	return (rlimit.rlim_max);
}

t_pageType getPageType(size_t size) {
    if (size <= (size_t)TINY_BLOCK_SIZE)
		return (TINY);
	else if (size <= (size_t)SMALL_BLOCK_SIZE)
		return (SMALL);
	return (LARGE);
}

size_t getPageSize(size_t size) {

    t_pageType type = getPageType(size_t size);

    if (type == TINY)
		return ((size_t)TINY_ALLOCATION_SIZE);
	else if (type == SMALL)
		return ((size_t)SMALL_ALLOCATION_SIZE);
	return (size + sizeof(t_heap) + sizeof(t_block));

}

void *allocateNewPage(size_t size) {
    t_page *page;
    size_t pageSize = getPageSize(size);

    if (pageSize > getDataLimit())
        return NULL;

    page = (t_page *)mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (page == MAP_FAILED)
        return NULL;
    page->type = getPageType(size);
    page->totalSize = pageSize;
    page->availableSize = pageSize - sizeof(t_page);

    return (page);
}