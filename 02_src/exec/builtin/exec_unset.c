/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:46:27 by vic               #+#    #+#             */
/*   Updated: 2022/08/02 14:09:40 by vmusunga         ###   ########.fr       */
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
	if (previous && next)
		previous->next = next;
	else if (previous && !next)
		previous->next = NULL;
	else if (!previous && next)
		current = next;
	else
		current = NULL;
}

// doesnt work on first of the list
// unset TEST= should return an error (unset TEST -> OK)

int	exec_unset(t_cmd *command, t_data *data)
{
	int	i;
	char *name;
	t_list *tmp;

	i = 0;
	tmp = data->env;
	name = get_env_name(command->av[1]);
	// printf("%s\n", get_env_name(tmp->content));
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, name, ft_strlen(name)))
		{
			unset_from_env(&data->env, i);
			// print_lst(&data->env);
			return (0);
		}
		i++;
		tmp = tmp->next;
	}
	ft_putendl_fd("Error: Invalid parameter name", 2);
	return (0);
}
