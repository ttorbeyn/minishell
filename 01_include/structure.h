#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"



typedef struct	s_redirection{
	char			*path;
	int				chmod;	//O_RDONLY O_WRONLY | O_TRUNC | O_CREAT..
}				t_redirection;

typedef struct	s_cmd{		//one s_cmd for each cmds
	char			*cmd;
	int				ac;
	char			**av;
	t_redirection	in;
	t_redirection	out;	//storing in/out destination w/ their respective cmds
}				t_cmd;

typedef struct	s_data{
	t_list	*env;
	t_cmd	*cmd;
	char	**envp;
	int		cmd_count;
}				t_data;

#endif
