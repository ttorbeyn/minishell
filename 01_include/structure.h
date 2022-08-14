#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

typedef struct	s_data{
	t_list	*env;
	char	*line;
	int double_quotes;
	int simple_quotes;
	t_list	*cmds;
}				t_data;

typedef struct	s_cmd{
	char 			*type;
	char			*cmd;
	int				ac;
	char			**av;
	//t_redirection	out;
	//t_redirection	in;
}				t_cmd;

typedef struct	s_token {
	char	*content;
	char	*type;
	struct s_token *next;
}				t_token;

typedef struct	s_quoted {
	int		quoted;
	char	*content;
}				t_quoted;

#endif
