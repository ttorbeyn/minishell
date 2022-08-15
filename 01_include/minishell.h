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

//00_init
void	data_set(t_data *data, t_list **envp, char **env);
char	*get_line(t_data *data);

//01_lexer
int	lex(t_data *data);

//ft_strtok
char *create_token(t_list **token, char *begin, char *end);
t_list	*ft_strtok(char *line);

//ft_strtok_utils
int	is_space(char c);
int	is_delim(char c, char *delim);
int	is_separator(char *line);
int	check_quotes(int i, char *line);

//utils
void	print_lst(t_list **env);

/// BUILTINS
char	*get_env_content(char *name, t_list *env);
char	*get_env_name(char *str);
int		is_builtin(char *cmd);


#endif