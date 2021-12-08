#include "malloc.h"

void findPointer(void *ptr, t_page **ptrPage, t_block **ptrBlock) {
    t_page *page = *ptrPage;
    t_block *block;

    while (page) {
        printf("segv page: %p\n", block);
        block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));
        size_t exploredSize = sizeof(t_page);
        printf("segv block: %p\n", block);
        printf("block dataSize: %zu\n", block->dataSize);
        printf("segv pointer: %p\n", BLOCK_SHIFT_FORWARD(block, sizeof(t_block)));
        while (exploredSize < page->totalSize) {
            if (block->freed == FALSE)
                printf("allocated\n");
            if (block->freed == FALSE
            && ptr == BLOCK_SHIFT_FORWARD(block, sizeof(t_block))) {
                *ptrPage = page;
                *ptrBlock = block;
                return ;
            }
            block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);
            exploredSize += sizeof(t_block) + block->dataSize;
        }
        page = page->next;
    }

    *ptrPage = NULL;
    *ptrBlock = NULL;
    return ;
}

void divideBlock(t_block **block, size_t size) {
    t_block *tmp = *block;

    if (tmp->dataSize == size)
        return ;

    t_block *next = BLOCK_SHIFT_FORWARD(tmp, sizeof(t_block) + size);

    next->dataSize = tmp->dataSize - size;
    next->freed = TRUE;
    tmp->dataSize = size;
    tmp->freed = FALSE;
}

void* findAvailableBlock(t_page *page, size_t size) {

    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));

    while (block->dataSize < size)
        block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);

    divideBlock(&block, size);
    page->availableSize -= size;
    page->blockCount++;
    page->maxDefragSize = findMaxDefragSize(page);

    return block;
}