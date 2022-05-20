#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

#include <signal.h>

typedef struct	s_data
{
	char **envp;
}				t_data;

#endif
