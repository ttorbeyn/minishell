/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:33:24 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/02 15:52:56 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

char	*get_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	if (!pwd)
		return_error("Error\n", NULL, 0);
	return (pwd);
}

char	*get_env_content(char *name, t_list *env)
{
	char *tmp;
	char *target;
	char *content;

	target = NULL;
	tmp = ft_strjoin(name, "=");
	while (env)
	{
		content = (char*)env->content;
		if (!ft_strncmp(content, tmp, ft_strlen(tmp)))
			target = ft_strdup(&content[ft_strlen(name) + 1]); //(=HOME)
		env = env->next;
	}
	free(tmp);
	// if (target)
	// 	free(target);
	return (target);
}

char	*get_env_name(char *str)
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
	while (i < len + 1)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
