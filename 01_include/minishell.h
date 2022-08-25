#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "structure.h"
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

void	data_set(t_data *data, t_list **envp, char **env);


/// EXEC ///
int		cmd_switch(t_data *data);
int		exec_builtin(t_data *data, int i);
void	executer(t_cmd cmd, t_data *data);

///PIPES ///
void	child_process(t_data *data, t_pipes *pipe, int i);
void	parent_process(t_data *data, t_pipes *pipe, int pid, int i);
void	ft_fork(t_data *data, t_pipes *pipe, int i);
void	lauching_process(t_data *data);
	//PIPES UTILS
void	short_dup(int x, int y);
void	close_pipe(int *end);
void	dup_close_pipe(int end, int fd, int *ends);
	//REDIR
void	redirections(t_data *data, t_pipes *pipe, int i);

/// BUILTINS ///
char	*get_pwd(void);
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);

int		exec_cd(t_cmd command, t_data *data);
int		exec_echo(t_cmd command);
int		exec_env(t_cmd command, t_data *data);
int		exec_pwd(t_data *data);
int		exec_export(t_cmd command, t_data *data);
int		exec_unset(t_cmd command, t_data *data);

/// UTILS ///
int		check_builtin(char *cmd);
char	*check_path(char **env, char *cmd);
int		return_error(char *msg, int system);
void	print_lst(t_list **env);


#endif