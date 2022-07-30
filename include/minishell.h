#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

<<<<<<< HEAD
=======
# include <signal.h>
>>>>>>> fe88b5b2a92002d28103bea2005388be3da2d8ba

typedef struct	s_shell{
	char*	env;
}				t_shell;

typedef struct	s_command{
	char			*cmd;
	int				ac;
	char			**av;
	//t_redirection	out;
	//t_redirection	in;
}				t_command;




#endif