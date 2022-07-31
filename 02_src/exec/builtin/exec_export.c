/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:46:27 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 22:44:22 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

static int check_valid(char *av)
{
	int	i;

	i = 0;
	if (!ft_strchr(av, '='))
		return (1);
	while (ft_strncmp(&av[i], "=", 1) && av[i])
	{
		if (!ft_isdigit((int)av[i]))
			return (1);
		if (av[i] == '-' || av[i] == '.' || av[i] == '{' || av[i] == '}'
			|| av[i] == '*' || av[i] == '#' || av[i] == '@' || av[i] == '!'
			|| av[i] == '^' || av[i] == '~' || av[i] == '\"' || av[i] == '|'
			|| av[i] == '\'' || av[i] == '$' || av[i] == ';' || av[i] == '&'
			|| !ft_isascii(av[i]) || ft_isspace(av[i]))
			return (1);
		if (av[i] == '+' && av[i + 1] != '=')
			return (1);
		i++;
	}
	return (0);
}

/*
	set_env (or export) adds or modifies environement variables in env
*/

int	exec_export(t_cmd command, t_data *data)
{
	char *name;

	if (!data->env || !command.av[1] || command.av[1][0] == '\0')
		return (1);
	if (check_valid(command.av[1]))
		return (1);
	name = get_env_name(command.av[1]);
	while (data->env)
	{
		if (ft_strncmp(data->env->content, name, ft_strlen(name)))
		{
			data->env->content = ft_strdup(command.av[1]);
			return(0);
		}
		data->env = data->env->next;
	}
	ft_lstadd_back(&data->env, ft_lstnew(command.av[1]));
	return (0);
}
