#include "./includes/malloc.h"

void *test_malloc_in_thread() {

    char *ptr1 = malloc(1);
    printf("TINY ptr: %p\n", ptr1);
    ptr1[1] = '\0';
    char *ptr1b = malloc(128);
    printf("TINY ptr b: %p\n", ptr1b);
    ptr1b[1] = '\0';
    char *ptr2 = malloc(240);
    printf("SMALL ptr: %p\n", ptr2);
    ptr2[239] = '\0';
    char *ptr2b = malloc(736);
    printf("SMALL ptr b: %p\n", ptr2b);
    ptr2b[238] = '\0';
    char *ptr2c = malloc(1024);
    printf("SMALL ptr c: %p\n", ptr2c);
    ptr2c[240] = '\0';
    char *ptr3 = malloc(2048);
    printf("LARGE ptr: %p\n", ptr3);
    ptr3[2047] = '\0';
    char *ptr4 = malloc(4096);
    printf("ptr 4096: %p\n", ptr4);
    ptr4[4096] = '\0';
    char *ptr5 = malloc(1024 * 1024);
    printf("ptr 1024 * 1024: %p\n", ptr5);
    ptr4[4096] = '\0';
    char *ptr6 = malloc(1024 * 1024 * 16);
    printf("ptr 1024 * 1024 * 16: %p\n", ptr6);
    ptr4[4096] = '\0';
    char *ptr7 = malloc(1024 * 1024 * 128);
    printf("ptr 1024 * 1024 * 128: %p\n", ptr7);
    ptr4[4096] = '\0';

    show_alloc_mem();

    // ptr2 = realloc(ptr2, 280);
    // printf("SMALL ptr realloc: %p\n", ptr2);

    // show_alloc_mem();

    // ptr2 = realloc(ptr2, 220);
    // printf("SMALL ptr realloc: %p\n", ptr2);

    // show_alloc_mem();

    // ptr4 = realloc(ptr4, 4096 * 6);
    // printf("XXL ptr realloc: %p\n", ptr4);

    // show_alloc_mem();

    free(ptr1);
    free(ptr1b);
    free(ptr2);
    free(ptr2b);
    free(ptr2c);
    free(ptr3);
    free(ptr4);
    free(ptr5);
    free(ptr6);
    free(ptr7);
    free(NULL);

    // show_alloc_mem();

    return NULL;
}

int main(void) {

    printf("%d\n", TINY_ALLOCATION_SIZE);
    printf("%d\n", SMALL_ALLOCATION_SIZE);

    // pthread_t				*pthread = malloc(sizeof(pthread_t));

    // pthread_create(pthread, NULL, test_malloc_in_thread, NULL);

    char *ptr1 = malloc(1);
    printf("TINY ptr: %p\n", ptr1);
    ptr1[1] = '\0';
    char *ptr1b = malloc(128);
    printf("TINY ptr b: %p\n", ptr1b);
    ptr1b[1] = '\0';
    char *ptr2 = malloc(240);
    printf("SMALL ptr: %p\n", ptr2);
    ptr2[239] = '\0';
    char *ptr2b = malloc(736);
    printf("SMALL ptr b: %p\n", ptr2b);
    ptr2b[238] = '\0';
    char *ptr2c = malloc(1024);
    printf("SMALL ptr c: %p\n", ptr2c);
    ptr2c[240] = '\0';
    char *ptr3 = malloc(2048);
    printf("LARGE ptr: %p\n", ptr3);
    ptr3[2047] = '\0';
    char *ptr4 = malloc(4096);
    printf("ptr 4096: %p\n", ptr4);
    ptr4[4096] = '\0';
    char *ptr5 = malloc(1024 * 1024);
    printf("ptr 1024 * 1024: %p\n", ptr5);
    ptr4[4096] = '\0';
    char *ptr6 = malloc(1024 * 1024 * 16);
    printf("ptr 1024 * 1024 * 16: %p\n", ptr6);
    ptr4[4096] = '\0';
    char *ptr7 = malloc(1024 * 1024 * 128);
    printf("ptr 1024 * 1024 * 128: %p\n", ptr7);
    ptr4[4096] = '\0';

    show_alloc_mem();

    // for (int i = 0; i < 200; i++) {
    //     malloc(128);
    // }

    // show_alloc_mem();

    // ptr2 = realloc(ptr2, 280);
    // printf("SMALL ptr realloc: %p\n", ptr2);

    // show_alloc_mem();

    // ptr2 = realloc(ptr2, 220);
    // printf("SMALL ptr realloc: %p\n", ptr2);

    // show_alloc_mem();

    // ptr4 = realloc(ptr4, 4096 * 6);
    // printf("XXL ptr realloc: %p\n", ptr4);

    // show_alloc_mem();

    free(ptr1);
    free(ptr1b);
    free(ptr2);
    free(ptr2b);
    free(ptr2c);
    free(ptr3);
    free(ptr4);
    free(ptr5);
    free(ptr6);
    free(ptr7);
    free(NULL);

    show_alloc_mem();

    return 0;
}