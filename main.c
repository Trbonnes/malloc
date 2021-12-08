#include "./includes/malloc.h"

int main(void) {

    void *ptr1 = malloc(2);
    printf("TINY ptr: %p\n", ptr1);
    void *ptr2 = malloc(240);
    printf("SMALL ptr: %p\n", ptr2);
    void *ptr3 = malloc(2048);
    printf("LARGE ptr: %p\n", ptr3);
    char *ptr4 = malloc(4096 * 8);
    printf("XXL ptr: %p\n", ptr4);
    ptr4[4096] = '\0';

    show_alloc_mem();

    ptr2 = realloc(ptr2, 280);
    printf("SMALL ptr realloc: %p\n", ptr2);

    show_alloc_mem();

    ptr2 = realloc(ptr2, 220);
    printf("SMALL ptr realloc: %p\n", ptr2);

    show_alloc_mem();

    ptr4 = realloc(ptr4, 4096 * 6);
    printf("XXL ptr realloc: %p\n", ptr4);

    show_alloc_mem();

    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);

    show_alloc_mem();

    free(NULL);

    return 0;
}