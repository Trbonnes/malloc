#include "../includes/malloc.h"

int	main(void) {

    printf("-- TEST 0 -- \n\n");

	int		i;
	char	*addr = (char*)malloc(1024);

	i = 0;
	while (i < 1024) {
		addr[i++] = 42;
	}

	return 0;
}