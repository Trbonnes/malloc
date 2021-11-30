CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC -I${INCLUDES} -c

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRCS = ./malloc.c ./realloc.c ./free.c

OBJECTSDIR = objs
OBJS = $(addprefix $(OBJECTSDIR)/, $(subst .c,.o,$(SRCS)))

INCLUDES =	./includes/malloc.h

NAME =		libft_malloc.so

LINK = 	ar -x libft.a
		-shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0   *.o

LIBFT = cd libft && make bonus

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