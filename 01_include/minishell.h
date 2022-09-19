/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:32:20 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/19 20:33:49 by vmusunga         ###   ########.fr       */
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
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WORD 0
# define PIPE 1
# define GREAT 2
# define LESS 3
# define DGREAT 4
# define DLESS 5

int		g_exit;

//PARSING

//00_init
void	envp_init(t_data *data, char **env);
char	*get_line(char *str);
void	data_set(t_data *data, t_list **envp, char **env);

//01_lexer
int		check_separator(t_token **token);
int		count_cmd(t_token **token);
int		lex(t_data *data);

//02_ft_strtok
int		token_type(char *token);
char	*create_token(t_token **token, char *begin, char *end);
int		tok_sep(t_token **token, char **tmp, char *line, int i);
int		init_token(char **line, char **tmp, t_token **token);
t_token	*ft_strtok(char *line);

//02_ft_strtok_utils
t_token	*free_out(t_token **token, char **line);
t_token	*ft_toknew(char *content, int type);
void	ft_tokadd_back(t_token **token, t_token *new);
int		is_separator(char *line);
int		check_quotes(int i, char *line);

//03_parser
void	cmd_init(t_cmd *cmd);
t_token	*count_arg(t_token *token, t_cmd *cmd);
t_token	*make_av(t_token *token, t_cmd *cmd);
int		parser(t_data *data);

//03_parser_utils
t_token	*delete_tok_null_begin(t_token *token);
t_token	*delete_tok_null(t_data *data);

//04_quotes
void	ft_free_str(char **begin, char **middle, char **end);
int		change_env_tok(t_data *data, t_token *token, int i);
char	*change_env_str(char *quoted, t_data *data);
int		remove_quotes(t_token *token, int i, char quote, t_data *data);
t_token	*clean_tok(t_data *data);

//04_quotes_utils
char	*double_join(char*s1, char *s2);
char	*triple_join(char *s1, char *s2, char *s3);

//04_redirection
t_here	*ft_herenew(char *limit);
void	ft_hereadd_back(t_here **token, t_here *new);
t_token	*cmd_redirection(t_token *token, t_redir *redir, int chmod);
t_token	*redirection(t_token *token, t_cmd *cmd);

//98_free
void	ft_lstfree(t_list **lst);
void	ft_tokfree(t_token **tok);
void	ft_herefree(t_here **here);

//99_utils
int		is_space(char c);
int		ft_error(char *errmsg, int errnum);
void	ft_free_data(t_data *data);
void	ft_free_cmd(t_data *data);
void	ft_free_env(t_data *data);

/// EXEC ///
int		cmd_switch(t_data *data);
int		exec_builtin(t_data *data, int i, t_pipes *pipe);
int		exec_old_builtin(t_data *data, int i);
void	executer(t_cmd cmd, t_data *data);

///PIPES ///
void	child_process(t_data *data, t_pipes *pipe, int i);
void	parent_process(t_data *data, t_pipes *pipe, pid_t pid, int i);
void	ft_fork(t_data *data, t_pipes *pipe, int i);
void	lauching_process(t_data *data, t_pipes *p);
	//PIPES UTILS
void	short_dup(int x, int y);
void	close_pipe(int *end);
void	dup_close_pipe(int end, int fd, int *ends);
	//REDIR
int		redirections(t_data *data, t_pipes *pipe, int i);
int		open_heredoc(t_here *doc);
void	rl_replace_line(const char *text, int clear_undo);
void	signal_handler(int signum);
void	signal_handler2(int signum);

/// BUILTINS ///
char	*get_pwd(void);
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);

int		exec_cd(t_cmd command, t_data *data);
int		exec_echo(t_cmd command);
void	update_envp(t_data *data);
int		exec_env(t_cmd command, t_data *data);
int		exec_pwd(t_data *data, t_pipes *p);
int		exec_export(t_cmd command, t_data *data);
int		exec_unset(t_cmd command, t_data *data);
int		exec_exit(t_cmd cmd);

/// UTILS ///
int		check_builtin(char *cmd);
char	*check_path(char **env, char *cmd);
int		return_error(char *msg, char *msg2, int system);
int		return_error_exit(char *msg, char *msg2, int system);
void	ft_abort(char *str);
void	print_lst(t_list **env);

//TO DELETE
void	print_tok(t_token **token);
int		print_cmd(t_data *data);

#endif
