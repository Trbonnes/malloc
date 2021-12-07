#include "./includes/malloc.h"

int main(void) {

    void *ptr = malloc(1);
    printf("TINY ptr: %p\n", ptr);
    void *ptr2 = malloc(720);
    printf("SMALL ptr: %p\n", ptr2);
    void *ptr3 = malloc(2048);
    printf("LARGE ptr: %p\n", ptr3);
    void *ptr4 = malloc(4096 * 8);
    printf("XXL ptr: %p\n", ptr4);

    return 0;
}