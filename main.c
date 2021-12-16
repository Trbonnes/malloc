#include "./includes/malloc.h"

void *test_malloc_in_thread() {

    char *ptr1 = malloc(128);
    printf("TINY ptr: %p\n", ptr1);
    ptr1[1] = '\0';
    char *ptr1b = malloc(128);
    printf("TINY ptr b: %p\n", ptr1b);
    ptr1b[1] = '\0';
    char *ptr2 = malloc(240);
    printf("SMALL ptr: %p\n", ptr2);
    ptr2[239] = '\0';
    char *ptr2b = malloc(239);
    printf("SMALL ptr b: %p\n", ptr2b);
    ptr2b[238] = '\0';
    char *ptr2c = malloc(241);
    printf("SMALL ptr c: %p\n", ptr2c);
    ptr2c[240] = '\0';
    char *ptr3 = malloc(2048);
    printf("LARGE ptr: %p\n", ptr3);
    ptr3[2047] = '\0';
    // ptr3[2048] = '\0';
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
    free(ptr1b);
    free(ptr2);
    free(ptr2b);
    free(ptr2c);
    free(ptr3);
    free(ptr4);
    free(NULL);

    show_alloc_mem();

    return NULL;
}

int main(void) {

    pthread_t				*pthread = malloc(sizeof(pthread_t));

    pthread_create(pthread, NULL, test_malloc_in_thread, NULL);

    // char *ptr1 = malloc(128);
    // printf("TINY ptr: %p\n", ptr1);
    // ptr1[1] = '\0';
    // char *ptr1b = malloc(128);
    // printf("TINY ptr b: %p\n", ptr1b);
    // ptr1b[1] = '\0';
    // char *ptr2 = malloc(240);
    // printf("SMALL ptr: %p\n", ptr2);
    // ptr2[239] = '\0';
    // char *ptr2b = malloc(239);
    // printf("SMALL ptr b: %p\n", ptr2b);
    // ptr2b[238] = '\0';
    // char *ptr2c = malloc(241);
    // printf("SMALL ptr c: %p\n", ptr2c);
    // ptr2c[240] = '\0';
    // char *ptr3 = malloc(2048);
    // printf("LARGE ptr: %p\n", ptr3);
    // ptr3[2047] = '\0';
    // // ptr3[2048] = '\0';
    // char *ptr4 = malloc(4096 * 8);
    // printf("XXL ptr: %p\n", ptr4);
    // ptr4[4096] = '\0';

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

    // char *freeAbortTest = ptr1 + 5;

    // free(freeAbortTest);

    // free(ptr1);
    // free(ptr1b);
    // free(ptr2);
    // free(ptr2b);
    // free(ptr2c);
    // free(ptr3);
    // free(ptr4);
    // free(NULL);

    // show_alloc_mem();

    return 0;
}