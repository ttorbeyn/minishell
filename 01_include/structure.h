/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:32:27 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:32:28 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

typedef struct s_pipes
{
	int		new_end[2];
	int		old_end[2];
	int		f_in;
	int		f_out;
}				t_pipes;

typedef struct s_here
{
	char	*limit;
	void	*next;
}				t_here;

typedef struct s_redir
{
	char			*path;
	int				chmod;
	t_here			*doc;
}				t_redir;

typedef struct s_cmd
{
	int				ac;
	char			**av;
	t_redir			in;
	t_redir			out;
}				t_cmd;

typedef struct s_token {
	char			*content;
	int				type;
	struct s_token	*next;
}				t_token;

typedef struct s_data{
	char	*line;
	t_list	*env;
	t_token	*token;
	int		nb_cmd;
	t_cmd	*cmds;
	char	**envp;
}				t_data;

#endif
