CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -nostdlib -fPIC -c -I${INCLUDES}
LFLAGS = -Wall -Wextra -Werror -g -shared -o

# Environment
ifeq (${HOSTTYPE},)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIBRARY_PATH = $(shell pwd)
OSTYPE = $(shell uname -s)

# Sources
SRCDIR = src
SRCS = malloc.c realloc.c free.c page.c block.c
OBJECTSDIR = objs
OBJS = $(addprefix $(OBJECTSDIR)/, malloc.o realloc.o free.o page.o block.o)

INCLUDES = includes

# Shared library
NAME =	libft_malloc_${HOSTTYPE}.so


ifneq (${OSTYPE}, Linux)
LINK = ${CC} ${LFLAGS} ${NAME} ${OBJS} -Wl,-force_load libft.a && ln -sf ${NAME} libft_malloc.so
else
LINK = 	${CC} ${LFLAGS} ${NAME} ${OBJS} -Wl,--whole-archive libft.a && ln -sf ${NAME} libft_malloc.so
endif

# Libft
LIBFT = cd libft && make bonus

# Compilation
${OBJECTSDIR}/%.o: ${SRCDIR}/%.c ${INCLUDES}
	mkdir -p ${OBJECTSDIR}
	${CC} ${CFLAGS} $< -o $@

${NAME}:	${OBJS} ${INCLUDES}
			${LIBFT}
			${LINK}
			export LD_LIBRARY_PATH=${LIBRARY_PATH}:$$LD_LIBRARY_PATH

all:		${NAME}

libft:		
			${LIBFT}

test:		${NAME}
			${CC} -L${LIBRARY_PATH} -Wall -Wextra -Werror -g -fsanitize=address main.c -lft_malloc

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