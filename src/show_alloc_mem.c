#include "malloc.h"

void printPointer(size_t addr, size_t length) {
	char	*str = "0123456789ABCDEF";

	if (addr / 16)
		printPointer(addr / 16, length - 1);
	else {
		ft_putstr_fd("0x", 1);
		while (--length > 0)
			ft_putstr_fd("0", 1);
	}

	write(1, &str[addr % 16], 1);
}

size_t printBlocks(t_page *page) {
    t_block *block = BLOCK_SHIFT_FORWARD(page, sizeof(t_page));
	void *start = NULL;
	void *end = NULL;
	size_t	size = 0;

	for (size_t i = 0; i < page->blockCount; i++) {
		start = BLOCK_SHIFT_FORWARD(block, sizeof(t_block));
		end = start + block->dataSize;
		if (block->freed == FALSE) {
            printPointer((size_t)start, 9);
			ft_putstr_fd(" - ", 1);
            printPointer((size_t)end, 9);
			ft_putstr_fd(" : ", 1);
            ft_putnbr_fd(block->dataSize, 1);
			ft_putstr_fd(" bytes\n", 1);
			size += block->dataSize;
		}
		block = BLOCK_SHIFT_FORWARD(block, sizeof(t_block) + block->dataSize);
	}
	return size;
}

void printPageHeader(t_page *page) {

    if (page->type == TINY)
	    ft_putstr_fd("TINY", 1);
    else if (page->type == SMALL)
	    ft_putstr_fd("SMALL", 1);
    else
	    ft_putstr_fd("LARGE", 1);
	ft_putstr_fd(" : ", 1);
	printPointer((size_t)page, 9);
	ft_putstr_fd("\n", 1);
}

void show_alloc_mem() {
	t_page	*last = getLastPage();
	size_t	totalSize = 0;

    ft_putstr_fd("\nALLOCATED MEMORY :\n", 1);

	while (last) {
        printPageHeader(last);
		totalSize += printBlocks(last);
		last = last->prev;
	}
	ft_putstr_fd("Total : ", 1);
	ft_putnbr_fd(totalSize, 1);
	ft_putstr_fd(" bytes\n\n", 1);
}