NAME	=	libftprintf.a

SRCS	=	ft_printf.c print_char.c print_num.c print_utils.c

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all: ${NAME}

${NAME}:${OBJS}
		ar -rcs $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY:
	all clean fclean re