#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

typedef struct	s_data{
	t_list	*env;
}				t_data;

typedef struct	s_cmd{
	char			*cmd;
	int				ac;
	char			**av;
	//t_redirection	out;
	//t_redirection	in;
}				t_cmd;

#endif
