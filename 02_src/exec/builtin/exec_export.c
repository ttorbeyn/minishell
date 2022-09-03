/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:46:27 by vic               #+#    #+#             */
/*   Updated: 2022/09/04 00:19:50 by vmusunga         ###   ########.fr       */
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

int	empty_export(t_data *data, t_pipes *p)
{
	t_list *tmp;

	tmp = data->env;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		write(p->f_out, tmp->content, ft_strlen(tmp->content));
		write(p->f_out, "\n", 1);
		tmp = tmp->next;
	}
	return (0);
}

int	exec_export(t_cmd command, t_data *data, t_pipes *p)
{
	char *name;
	t_list *tmp;

	if (!data->env)
		return (1);
	if (!command.av[1])
		return (empty_export(data, p));
	if (check_valid(command.av[1]))
		return (1);
	tmp = data->env;
	name = get_env_name(command.av[1]);
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, name, ft_strlen(name)))
		{
			tmp->content = ft_strdup(command.av[1]);
			return(0);
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&data->env, ft_lstnew(command.av[1]));
	return (0);
}
