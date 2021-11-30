CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC ${INCLUDES} -c

# Environment
ifeq (${HOSTTYPE},)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
LIBRARY_PATH = $(shell pwd)

# Sources
SRCS = src/malloc.c src/realloc.c src/free.c
OBJECTSDIR = objs
OBJS = $(addprefix $(OBJECTSDIR)/, malloc.o realloc.o free.o)

INCLUDES =	-I .
HEADERS = includes/malloc.h

# Shared library
NAME =		libft_malloc.so
OSNAME =	libft_malloc_${HOSTTYPE}.so

LINK = 	${CC} -shared -o ${NAME} ${OBJS} && ln -sf ${NAME} ${OSNAME}

# Libft
LIBFT = cd libft && make bonus
UNLINK_LIBFT = ar -x libft.a --output ${OBJECTSDIR}

# Compilation
${OBJECTSDIR}/%.o: ${SRCS} ${HEADERS}
	mkdir -p ${OBJECTSDIR}
	${CC} ${CFLAGS} $< -o $@ ${INCLUDES}

${NAME}:	${OBJS} ${HEADERS}
			cd libft && make bonus
			${LINK}
			export LD_LIBRARY_PATH=${LIBRARY_PATH}:$$LD_LIBRARY_PATH

all:		${NAME}

test:		${NAME}
			${CC} -L${LIBRARY_PATH} -Wall -Wextra -Werror main.c -lft_malloc_${HOSTTYPE}

clean:
			rm -f ${OBJS}
			rm -rf ${OBJECTSDIR}
			rm -f libft.a
			cd libft && make clean

fclean:		clean
			rm -f ${NAME}
			rm -f ${OSNAME}
			rm -f a.out
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test