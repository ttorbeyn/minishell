/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:38:24 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/17 02:15:39 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	print_lst(t_list **env)
{
	t_list	*first;
	int		len;
	int		i;

	first = *env;
	len = ft_lstsize(env);
	i = 0;
	while (i < len)
	{
		printf("%d:	%s\n", i, (char *)first->content);
		first = first->next;
		i++;
	}
}

int	check_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 2))
		return (1);
	if (!ft_strncmp(cmd, "echo", 4))
		return (2);
	if (!ft_strncmp(cmd, "exit", 4))
		return (3);
	if (!ft_strncmp(cmd, "env", 3))
		return (4);
	if (!ft_strncmp(cmd, "pwd", 3))
		return (5);
	if (!ft_strncmp(cmd, "export", 6))
		return (6);
	if (!ft_strncmp(cmd, "unset", 5))
		return (7);
	return (0);
}

/*
check_path:
	Tests all paths in envp for a specific cmd. 
	Rutruns either the path or NULL if none found.
*/
char	*check_path(char **envp, char *cmd)
{
	int		x;
	char	*tmp;
	char	*path;
	char	**path_tab;

	x = 0;
	while (ft_strncmp(envp[x], "PATH=", 5) != 0 && envp[x])
		x++;
	path_tab = ft_split(envp[x] + 5, ':');
	x = 0;
	while (path_tab[x])
	{
		tmp = ft_strjoin(path_tab[x], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		x++;
	}
	x = -1;
	while (path_tab[++x])
		free(path_tab[x]);
	free(path_tab);
	return (NULL);
}

int	return_error(char *msg, char *msg2, int system)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(msg, 2);
	if (msg2)
		ft_putstr_fd(msg2, 2);
	write(2, "\n", 1);
	// g_exit = WTERMSIG(system);
	return (system);
}

int	return_error_exit(char *msg, char *msg2, int system)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(msg, 2);
	if (msg2)
		ft_putstr_fd(msg2, 2);
	write(2, "\n", 1);
	g_exit = system;
	// printf("exit lOL %d\n", g_exit);
	// g_exit = WTERMSIG(system);
	exit (g_exit);
}

void	ft_abort(char *str)
{
	return_error(str, NULL, 255);
	exit(0);
}
