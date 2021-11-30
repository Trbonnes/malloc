CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC -I${INCLUDES} -c

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRCS = src/malloc.c src/realloc.c src/free.c
OBJECTSDIR = objs
OBJS = $(addprefix $(OBJECTSDIR)/, $(subst .c,.o,$(SRCS)))

INCLUDES =	includes

NAME =		libft_malloc.so

LINK = 	${CC} -shared -Wl,-soname, libft_malloc.so *.o && ln -sf libft_malloc_${HOSTTYPE}.so

LIBFT = cd libft && make bonus
UNLINK_LIBFT = ar -x libft.a --output ${OBJECTSDIR}

${NAME}:	${OBJS} ./includes/malloc.h
			cd libft && make bonus
			${LINK} ${NAME} ${OBJS}
			ranlib libft_malloc.so

all:		${NAME}

test:		${NAME}
			${CC}


clean:
			rm -f ${OBJS}
			cd libft && make clean

fclean:		clean
			rm -f ${NAME}
			rm -f a.out
			cd libft && make fclean

re: 		fclean all

.PHONY: all clean fclean re test