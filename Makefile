# Variables
NAME = libasm.a
EXEC = libasm_exec

SRCS_ASM = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s
SRCS_C = main.c

AS = nasm -felf64
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_ASM = ${SRCS_ASM:.s=.o}
OBJS_C = ${SRCS_C:.c=.o}

# Règles
${NAME}: ${OBJS_ASM}
	ar rc ${NAME} ${OBJS_ASM}

all: ${NAME}

exec: ${NAME} ${OBJS_C}
	${CC} ${CFLAGS} ${OBJS_C} ${NAME} -o ${EXEC}

.s.o:
	${AS} -o $@ $<

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS_ASM} ${OBJS_C}

fclean: clean
	rm -rf ${NAME} ${EXEC}

re: fclean all
