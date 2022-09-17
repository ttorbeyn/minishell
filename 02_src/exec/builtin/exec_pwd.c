/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:21 by vic               #+#    #+#             */
/*   Updated: 2022/09/17 13:51:57 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_pwd(t_data *data, t_pipes *p, int i)
{
	char	*tmp;

	if (data->cmds[i].av[1])
		return(return_error("Error: Too many arguments", NULL, 2));
	tmp = get_env_content("PWD", data->env);
	ft_putendl_fd(tmp, p->f_out);
	free(tmp);
	return (0);
}
