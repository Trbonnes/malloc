#pragma once

#include <sys/resource.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>

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

    struct s_block *next;
    struct s_block *prev;

}   t_block;

typedef struct s_page {

    size_t totalSize;
    size_t availableSize;
    size_t blockCount;

    t_pageType type;

    struct s_page *next;
    struct s_page *prev;

    struct s_block *blocks;

}   t_page;


#define PAGE_SHIFT(start)((void *)start + sizeof(t_page))
#define BLOCK_SHIFT(start)((void *)start + sizeof(t_block))

/*
For tiny blocks, let’s say we use 128 bytes for a maximum malloc size.
If we fill a page with 128 of them, it gives us a TINY_ALLOCATION_SIZE of 16KB (128 * 128).
Since each malloc has to store its metadata (sizeof(t_block) = 32 bytes), we won’t be able to store all the 128 blocks.
16 KB / (128 + 32) = 102.4. So, counting the t_page at the start of the 16KB heap , we can store 102 times a 128 bytes malloc
*/

#define TINY_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_ALLOCATION_SIZE / 128)
#define SMALL_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_ALLOCATION_SIZE / 128)

t_page *g_page_head = NULL;

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem();

/*
Page methods
*/

static rlim_t getDataLimit(void);
t_pageType getPageType(size_t size);
size_t getPageSize(size_t size);
void *allocateNewPage(size_t size);