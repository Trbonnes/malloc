#include "../includes/malloc.h"

int	main(void) {

    printf("-- TEST 5 -- \n\n");

	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();

	return 0;
}