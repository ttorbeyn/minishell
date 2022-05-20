CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -lreadline

INCLUDE			=	-I include

SRC				=	./main.c

OBJS			=	$(SRC:.c=.o)

RM				= 	@rm -f

NAME			=	minishell

all: 		$(NAME)

$(NAME):
			@$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) minishell

re:			fclean all

.PHONY:		all clean fclean re save