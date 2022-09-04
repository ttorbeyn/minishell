/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:21 by vic               #+#    #+#             */
/*   Updated: 2022/09/04 03:54:44 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_pwd(t_data *data, t_pipes *p)
{
	char *tmp;

	tmp = get_env_content("PWD", data->env);
	ft_putendl_fd(tmp, p->f_out);
	free(tmp);
	return (0);
}
