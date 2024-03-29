/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:46:27 by vic               #+#    #+#             */
/*   Updated: 2022/09/19 21:21:48 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

void	unset_from_env(t_list **env, int i)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	previous = ft_lstget(*env, i - 1);
	current = ft_lstget(*env, i);
	next = ft_lstget(*env, i + 1);
	if (i < 1)
	{
		current = *env;
		current = current->next;
		*env = current;
		return ;
	}
	if (previous && next)
		previous->next = next;
	else if (previous && !next)
		previous->next = NULL;
	else if (!previous && next)
		current = next;
	else
		current = NULL;
}

int	exec_unset(t_cmd command, t_data *data)
{
	int		i;
	char	*name;
	t_list	*tmp;

	i = 0;
	if (!command.av[1])
		return (return_error("unset: not enough arguments", NULL, 2));
	tmp = data->env;
	name = get_env_name(ft_strdup(command.av[1]));
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, name, ft_strlen(name)))
		{
			unset_from_env(&data->env, i);
			update_envp(data);
			free(tmp);
			return (0);
		}
		i++;
		tmp = tmp->next;
	}
	free(tmp);
	update_envp(data);
	return (return_error("unset: Invalid parameter name", NULL, 1));
}
