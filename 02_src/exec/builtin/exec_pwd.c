/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:21 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 20:13:02 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_pwd(char **env)
{
	char *tmp;

	tmp = get_env_content("PWD", env);
	ft_putendl_fd(tmp, 1);
	free(tmp);
	return (0);
}