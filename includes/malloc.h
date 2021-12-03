#pragma once

#include <sys/resource.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>

#include "libft.h"

#define BLOCK_SHIFT_FORWARD(start, offset)((void *)start + offset)
#define BLOCK_SHIFT_BACKWARD(start, offset)((void *)start - offset)

/*
For tiny blocks, let’s say we use 128 bytes for a maximum malloc size.
If we fill a page with 128 of them, it gives us a TINY_ALLOCATION_SIZE of 16KB (128 * 128).
Since each malloc has to store its metadata (sizeof(t_block) = 32 bytes), we won’t be able to store all the 128 blocks.
16 KB / (128 + 32) = 102.4. So, counting the t_page at the start of the 16KB heap , we can store 102 times a 128 bytes malloc

For a pagesize of 4096 bytes
TINY  - block < 128 bytes - heap 16 KB
SMALL - block < 1024 bytes - heap 128 KB
LARGE - block > 1024 bytes
*/

#define TINY_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_ALLOCATION_SIZE / 128)
#define SMALL_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_ALLOCATION_SIZE / 128)

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_pageType {
	TINY,
	SMALL,
    LARGE
}				t_pageType;

typedef struct s_block {
    
    size_t dataSize;
    t_bool freed;

}   t_block;

typedef struct s_page {

    size_t totalSize;
    size_t availableSize;
    size_t maxDefragSize;
    size_t blockCount;

    t_pageType type;

    struct s_page *next;
    struct s_page *prev;

}   t_page;

extern t_page *g_page_head;

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem();

/*
Page methods
*/

t_pageType getPageType(size_t size);
size_t getPageSize(size_t size);
void* allocateNewPage(size_t size);
void* findAvailablePage(size_t size);
size_t findMaxDefragSize(t_page *page);

/*
Block methods
*/

void *findAvailableBlock(t_page *page, size_t size);