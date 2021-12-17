CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -nostdlib -fPIC -c -I${INCLUDES}
LFLAGS = -Wall -Wextra -Werror -g -shared -o

# Environment
ifeq (${HOSTTYPE},)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIBRARY_PATH = $(shell pwd)

# Sources
SRCDIR = src
SRCS = malloc.c calloc.c realloc.c free.c page.c block.c show_alloc_mem.c
OBJECTSDIR = objs
OBJS = $(addprefix $(OBJECTSDIR)/, malloc.o calloc.o realloc.o free.o page.o block.o show_alloc_mem.o)

INCLUDES = includes

# Shared library
NAME =	libft_malloc_${HOSTTYPE}.so
LINK = ${CC} ${LFLAGS} ${NAME} ${OBJS} -Wl,-force_load libft.a && ln -sf ${NAME} libft_malloc.so

# Libft
LIBFT = cd libft && make

# Compilation
${OBJECTSDIR}/%.o: ${SRCDIR}/%.c ${INCLUDES}
	mkdir -p ${OBJECTSDIR}
	${CC} ${CFLAGS} $< -o $@

${NAME}:	${OBJS} ${INCLUDES}
			${LIBFT}
			${LINK}
			$(shell export LD_LIBRARY_PATH=${LIBRARY_PATH}:$$LD_LIBRARY_PATH)

all:		${NAME}

libft:		
			${LIBFT}

test:		${NAME}
			${CC} -L${LIBRARY_PATH} -g -fsanitize=address main.c -lft_malloc

correction:	${NAME}
			${CC} -o test0 ./test/test0.c
			${CC} -o test1 ./test/test1.c
			${CC} -o test2 ./test/test2.c
			${CC} -o test3 ./test/test3.c
			${CC} -o test4 ./test/test4.c
			${CC} -o test5 ./test/test5.c
			${CC} -L${LIBRARY_PATH} -o test6 ./test/test6.c -lft_malloc

clean:
			rm -f ${OBJS}
			rm -rf ${OBJECTSDIR}
			rm -f libft.a
			cd libft && make clean

fclean:		clean
			rm -f ${NAME}
			rm -f libft_malloc.so
			rm -f a.out test0 test1 test2 test3 test4 test5 test6
			rm -rf a.out.dSYM
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test libft correction