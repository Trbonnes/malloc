#include "malloc.h"

void findPointer(void *ptr, t_page **ptrPage, t_block **ptrBlock) {
    t_page *page = *ptrPage;
    t_block *block;

    while (page) {
        block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));
        for (size_t i = 0; i < page->blockCount; i++) {
            if (block->freed == FALSE
            && ptr == BLOCK_SHIFT_FORWARD(block, sizeof(t_block))) {
                *ptrPage = page;
                *ptrBlock = block;
                return ;
            }
            block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);
        }
        page = page->next;
    }

    *ptrPage = NULL;
    *ptrBlock = NULL;
    return ;
}

void divideBlock(t_page *page, t_block **block, size_t size) {
    t_block *tmp = *block;

    tmp->freed = FALSE;
    page->availableSize -= size;

    if (tmp->dataSize == size) {
        return ;
    }

    t_block *next = BLOCK_SHIFT_FORWARD(tmp, sizeof(t_block) + size);

    next->dataSize = tmp->dataSize - size - sizeof(t_block);
    next->freed = TRUE;

    tmp->dataSize = size;
    page->blockCount++;
}

void* findAvailableBlock(t_page *page, size_t size) {

    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));

    while (block->freed == FALSE || block->dataSize < size)
        block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);

    divideBlock(page, &block, size);
    page->maxDefragSize = findMaxDefragSize(page);

    return block;
}