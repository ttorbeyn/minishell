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

# define WORD 0
# define PIPE 1
# define GREAT 2
# define LESS 3
# define DGREAT 4
# define DLESS 5

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

//utils
int		ft_error(char *error);
void	print_lst(t_list **env);
void	print_tok(t_token **token);

/// BUILTINS
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);
int		is_builtin(char *cmd);


#endif