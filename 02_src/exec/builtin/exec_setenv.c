/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:46:27 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 20:13:02 by vmusunga         ###   ########.fr       */
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

char	*get_name(char *str)
{
	int i;
	int len;
	char *cpy;

	i = 0;
	len = 0;
	while (str[len])
	{
		if (str[len] == '=')
			break;
		len++;
	}
	cpy = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/*
	set_env (or export) adds or modifies environement variables in env
*/

int	exec_export(t_cmd command, t_data *data)
{
	int i;
	char *name;

	i = 0;
	if (!data->env || !command.av[1] || command.av[1][0] == '\0')
		return (1);
	if (check_valid(command.av[1]))
		return (1);

	name = get_name(command.av[1]);

	//check_exist(data, command);
	// search name in env;
	// if exists...
	// else ... 
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_cmd command;
// 	t_data *data;
// 	int i;

// 	// data->env = malloc(100);
// 	// data->env[0] = "TEST= blabla";
// 	command.av = av;
	

// 	i = exec_export(command, data);
// 	printf("%d\n", i);
// 	return (0);
// }