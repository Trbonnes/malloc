#include "../includes/malloc.h"

int	main(void) {

    printf("-- TEST 1 -- \n\n");

	int		i;
	char	*addr;

	i = 0;
	while (i < 1024) {
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	
	return 0;
}