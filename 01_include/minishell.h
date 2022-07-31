#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "structure.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

void	data_set(t_data *data, t_list **envp, char **env);

/// BUILTINS
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);
int		is_builtin(char *cmd);


#endif