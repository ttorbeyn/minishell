#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

typedef struct	s_cmd{
	int				ac;
	char			**av;
	//t_redirection	out;
	//t_redirection	in;
}				t_cmd;

typedef struct	s_token {
	char			*content;
	int				type;
	struct s_token	*next;
}				t_token;

typedef struct	s_data{
	char	*line;
	t_list	*env;
	t_token	*token;
	int 	nb_cmd;
	t_cmd	*cmds;
}				t_data;

#endif
