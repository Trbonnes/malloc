#include "../includes/malloc.h"

void divideBlock(t_block **block, size_t size) {
    t_block *tmp = *block

    if (tmp->dataSize == size)
        return ;

    t_block *next = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);

    next->dataSize = tmp->dataSize - size;
    next->freed = TRUE;
    tmp->dataSize = size;
    tmp->freed = FALSE;
}

void* findAvailableBlock(t_page *page, size_t size) {

    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));

    while (block->dataSize < size)
        block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);

    divideBlock(&block, size)
    page->availableSize -= size;
    page->blockCount++;
    page->maxDefragSize = findMaxDefragSize(page);

    return block;
}