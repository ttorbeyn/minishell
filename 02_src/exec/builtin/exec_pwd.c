/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:21 by vic               #+#    #+#             */
/*   Updated: 2022/09/18 15:23:28 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_pwd(t_data *data, t_pipes *p)
{
	char	*tmp;

	tmp = get_env_content("PWD", data->env);
	ft_putendl_fd(tmp, p->f_out);
	free(tmp);
	return (0);
}
