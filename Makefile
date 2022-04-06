NAME	= minishell

CC	= gcc

CFLAGS =  -Wall -Wextra -Werror -g

SRCS	= minishell.c\
		commands.c\

OBJS	= ${SRCS:.c=.o}

.c.o:
	make -C ./libft all
	${CC} ${CFLAGS} -c ${SRCS}

RM	= rm -f

$(NAME):	${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) ${OBJS} -lreadline libft/libft.a -L./libft


all:	$(NAME)

clean:
	${RM} ${OBJS}
	make -C ./libft clean

fclean:	clean
	${RM} ${NAME}
	make -C ./libft clean

re:	fclean all

.PHONY: 	all clean fclean
