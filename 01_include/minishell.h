/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:32:20 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/15 15:26:16 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define IN 6
# define OUT 7

int		g_exit;

//main
void	envp_init(t_data *data, char **env);
void	update_envp(t_data *data);

//PARSING

//00_init
char	*get_line(void);
void	data_set(t_data *data, t_list **envp, char **env);

//01_lexer
int		check_separator(t_token **token);
int		count_cmd(t_token **token);
int		lex(t_data *data);

//02_ft_strtok
int		token_type(char *token);
char	*create_token(t_token **token, char *begin, char *end);
t_token	*ft_strtok(char *line);

//02_ft_strtok_utils
t_token	*ft_toknew(char *content, int type);
void	ft_tokadd_back(t_token **token, t_token *new);
int		is_separator(char *line);
int		check_quotes(int i, char *line);

//03_parser
void	cmd_init(t_cmd *cmd);
t_token	*count_arg(t_token *token, t_cmd *cmd);
t_token	*make_av(t_token *token, t_cmd *cmd);
int		parser(t_data *data);

//04_quotes
int		remove_simple_quotes(t_token *token, int i);
char	*replace_env(char *quote, t_data *data);
int		remove_double_quotes(t_data *data, t_token *token, int i);
t_token	*remove_quotes(t_data *data);

//04_quotes_utils
char	*double_join(char*s1, char *s2);
char	*triple_join(char *s1, char *s2, char *s3);

//04_redirection
t_here	*ft_herenew(char *limit);
void	ft_hereadd_back(t_here **token, t_here *new);
t_token	*cmd_redirection(t_token *token, t_redir redir, int chmod);
t_token	*redirection(t_token *token, t_cmd *cmd);

//99_utils
int		is_space(char c);
int		ft_error(char *errmsg, int errnum);
void	print_tok(t_token **token);
int		print_cmd(t_data *data);

/// EXEC ///
int		cmd_switch(t_data *data);
int		exec_builtin(t_data *data, int i, t_pipes *pipe);
int		exec_old_builtin(t_data *data, int i);
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
void	signal_handler(int signum);
void	signal_handler2(int signum);

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
void	ft_abort(char *str);
void	print_lst(t_list **env);

#endif
