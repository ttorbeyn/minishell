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

# define WORD 0
# define PIPE 1
# define GREAT 2
# define LESS 3
# define DGREAT 4
# define DLESS 5

int		g_exit;

void	envp_init(t_data *data, char **env);

//00_init
void	data_set(t_data *data, t_list **envp, char **env);
char	*get_line(t_data *data);

//01_lexer
int	lex(t_data *data);

//02_ft_strtok
char *create_token(t_token **token, char *begin, char *end);
t_token	*ft_strtok(char *line);

//02_ft_strtok_utils
int	is_space(char c);
int	is_delim(char c, char *delim);
int	is_separator(char *line);
int	check_quotes(int i, char *line);

//03_parser
int	parser(t_data *data);

//99_utils
int		ft_error(char *error);
void	print_tok(t_token **token);


/// EXEC ///
int		cmd_switch(t_data *data);
int		exec_builtin(t_data *data, int i, t_pipes *pipe);
int	exec_old_builtin(t_data *data, int i);
void	executer(t_cmd cmd, t_data *data);

///PIPES ///
void	child_process(t_data *data, t_pipes *pipe, int i);
void	parent_process(t_data *data, t_pipes *pipe, int pid, int i);
void	ft_fork(t_data *data, t_pipes *pipe, int i);
void	lauching_process(t_data *data, t_pipes *p);
	//PIPES UTILS
void	short_dup(int x, int y);
void	close_pipe(int *end);
void	dup_close_pipe(int end, int fd, int *ends);
	//REDIR
void	redirections(t_data *data, t_pipes *pipe, int i);
int		open_heredoc(t_here *doc);

/// BUILTINS ///
char	*get_pwd(void);
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);

int		exec_cd(t_cmd command, t_data *data);
int		exec_echo(t_cmd command);
int		exec_env(t_cmd command, t_data *data, t_pipes *p);
int		exec_pwd(t_data *data, t_pipes *p);
int		exec_export(t_cmd command, t_data *data, t_pipes *p);
int		exec_unset(t_cmd command, t_data *data);
int		exec_exit(t_cmd cmd);


/// UTILS ///
int		check_builtin(char *cmd);
char	*check_path(char **env, char *cmd);
int		return_error(char *msg, char *msg2, int system);
void	ft_abort(char *str, int system);
void	print_lst(t_list **env);


#endif