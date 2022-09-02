#include "../../01_include/minishell.h"

t_token *count_arg(t_token *tmp, t_cmd *cmd)
{
	if (!tmp)
		return (0);
	while (tmp && tmp->type == WORD)
	{
		cmd->ac++;
		tmp = tmp->next;
	}
	while (tmp && (tmp->type == GREAT || tmp->type == LESS || tmp->type == DGREAT || tmp->type == DLESS))
		tmp = tmp->next;
	if (tmp && tmp->type == PIPE)
	{
		tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}

t_token *make_av(t_token *token, t_cmd *cmd)
{
	int i;
	t_token *tmp;


	tmp = token;
	token = count_arg(token, cmd);
	cmd->av = malloc(sizeof(char*) * (cmd->ac + 1));
	i = 0;
	while (i < cmd->ac)
	{
		cmd->av[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	cmd->av[i] = NULL;
	return (token);
}

int	parser(t_data *data)
{
	t_token *tmp;
	int i;

	i = 0;
	tmp = data->token;
	data->cmds = malloc(sizeof(t_cmd) * data->nb_cmd);
	while (i < data->nb_cmd)
	{
		tmp = make_av(tmp, &data->cmds[i]);
		i++;
	}
	return (0);
}