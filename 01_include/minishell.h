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
void	print_lst(t_list **env);

/// EXEC
void	executer(t_cmd *cmd, t_data *data);
void	executer(t_cmd *cmd, t_data *data);
int	one_cmd(t_cmd *cmd, t_data *data);

/// BUILTINS
char	*get_pwd(void);
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);
int		is_builtin(t_cmd *cmd, t_data *data);

int		exec_cd(t_cmd *command, t_data *data);
int		exec_echo(t_cmd *command);
int		exec_env(t_cmd *command, t_data *data);
int		exec_pwd(t_data *data);
int		exec_export(t_cmd *command, t_data *data);
int		exec_unset(t_cmd *command, t_data *data);

/// UTILS
int		return_error(char *msg, int system);
char	*check_path(char **env, char *cmd);



#endif