SRC = ft_printf.c

LIBFT_DIR = ./libft

OBJS = ${SRC:%.c=%.o}

NAME = libftprintf.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

INC_DIR = .

CPPFLAGS = -I${INC_DIR} -I${LIBFT_DIR}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS} libft
	ar rcs ${NAME} ${OBJS}
	ar -x ${LIBFT_DIR}/libft.a
	ar rcs ${NAME} *.o
	${RM} *.o

libft:
	cd ${LIBFT_DIR} && ${MAKE}

%.o: %.c
	${CC} ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS}
	cd ${LIBFT_DIR} && ${MAKE} clean

fclean: 
	${RM} ${NAME}
	cd ${LIBFT_DIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re libft
