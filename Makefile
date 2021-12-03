CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC -c

# Environment
ifeq (${HOSTTYPE},)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
LIBRARY_PATH = $(shell pwd)

# Sources
SRCS = src/malloc.c src/realloc.c src/free.c src/page.c src/block.c
OBJECTSDIR = objs
OBJS = $(addprefix $(OBJECTSDIR)/, malloc.o realloc.o free.o page.o block.o)

INCLUDES = includes

# Shared library
NAME =	libft_malloc_${HOSTTYPE}.so

LINK = 	${CC} -shared -o ${NAME} ${OBJS} && ln -sf ${NAME} libft_malloc.so

# Libft
LIBFT = cd libft && make bonus
UNLINK_LIBFT = ar -x libft.a --output ${OBJECTSDIR}

# Compilation
${OBJECTSDIR}/%.o: ${SRCS} 
	mkdir -p ${OBJECTSDIR}
	${CC} ${CFLAGS} $< -o $@ -I${INCLUDES}

${NAME}:	${OBJS} ${INCLUDES}
			cd libft && make bonus
			${LINK}
			export LD_LIBRARY_PATH=${LIBRARY_PATH}:$$LD_LIBRARY_PATH

all:		${NAME}

test:		${NAME}
			${CC} -L${LIBRARY_PATH} -Wall -Wextra -Werror main.c -lft_malloc

clean:
			rm -f ${OBJS}
			rm -rf ${OBJECTSDIR}
			rm -f libft.a
			cd libft && make clean

fclean:		clean
			rm -f ${NAME}
			rm -f libft_malloc.so
			rm -f a.out
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test