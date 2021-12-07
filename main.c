#include "./includes/malloc.h"

int main(void) {

    void *ptr1 = malloc(1);
    printf("TINY ptr: %p\n", ptr1);
    void *ptr2 = malloc(240);
    printf("SMALL ptr: %p\n", ptr2);
    void *ptr3 = malloc(2048);
    printf("LARGE ptr: %p\n", ptr3);
    void *ptr4 = malloc(4096 * 8);
    printf("XXL ptr: %p\n", ptr4);

    ptr4 = realloc(ptr4, 4096 * 6);
    printf("XXL ptr: %p\n", ptr4);

    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);

    free(NULL);

    return 0;
}