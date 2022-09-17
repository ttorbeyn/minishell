CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/include/readline/ -ltermcap

INCLUDE			=	-I include

LIBFT			=	./00_libft/ft_atoi.c \
					./00_libft/ft_isdigit.c \
					./00_libft/ft_isspace.c \
					./00_libft/ft_itoa.c \
					./00_libft/ft_isascii.c \
					./00_libft/ft_lstadd_back.c \
					./00_libft/ft_lstbefore_last.c \
					./00_libft/ft_lstlast.c \
					./00_libft/ft_lstnew.c \
					./00_libft/ft_lstget.c \
					./00_libft/ft_lstsize.c \
					./00_libft/ft_putendl_fd.c \
					./00_libft/ft_putstr_fd.c \
					./00_libft/ft_split.c \
					./00_libft/ft_strchr.c \
					./00_libft/ft_strdup.c \
					./00_libft/ft_strjoin.c \
					./00_libft/ft_strlen.c \
					./00_libft/ft_strncmp.c \
					./00_libft/ft_strndup.c \
					./00_libft/ft_strtrim.c \
					./00_libft/utils/ft_exit.c \
					./00_libft/ft_strrchr.c \
					./00_libft/ft_tolower.c

PARSING			=	./02_src/parsing/00_init.c \
					./02_src/parsing/01_lexer.c \
					./02_src/parsing/02_ft_strtok.c \
					./02_src/parsing/02_ft_strtok_utils.c \
					./02_src/parsing/03_parser.c \
					./02_src/parsing/04_quotes.c \
					./02_src/parsing/04_quotes_utils.c \
					./02_src/parsing/04_redirection.c \
					./02_src/parsing/99_utils.c \
					./02_src/main.c \

EXEC			=	./02_src/exec/builtin/builtin_utils.c \
					./02_src/exec/builtin/exec_echo.c \
					./02_src/exec/builtin/exec_env.c \
					./02_src/exec/builtin/exec_export.c \
					./02_src/exec/builtin/exec_pwd.c \
					./02_src/exec/builtin/exec_unset.c \
					./02_src/exec/builtin/exec_cd.c \
					./02_src/exec/utils.c \
					./02_src/exec/exec.c \
					./02_src/exec/pipes.c \
					./02_src/exec/pipe_utils.c \
					./02_src/exec/redirections.c \
					./02_src/exec/heredoc.c \
					./02_src/exec/exit_utils.c \
					./02_src/exec/builtin/exec_exit.c 

SRC				=	$(LIBFT) \
					$(PARSING) \
					$(EXEC)

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