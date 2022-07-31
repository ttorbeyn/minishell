#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_data{
	char*	envp;
}				t_data;

typedef struct	s_cmd{
	char			*cmd;
	int				ac;
	char			**av;
	//t_redirection	out;
	//t_redirection	in;
}				t_cmd;

#endif