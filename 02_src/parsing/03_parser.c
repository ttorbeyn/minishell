#include "../../01_include/minishell.h"

void cmd_init(t_cmd *cmd)
{
	cmd->ac = 0;
	cmd->av = NULL;
	cmd->in.path = NULL;
	cmd->in.chmod = 0;
	cmd->in.doc = NULL;
	cmd->out.path = NULL;
	cmd->out.chmod = 0;
	cmd->out.doc = NULL;
}

t_token *count_arg(t_token *token, t_cmd *cmd, t_data *data)
{
	if (!token)
		return (0);
	while (token && token->type == WORD)
	{
		cmd->ac++;
		token = token->next;
	}
	if (token && token->type == PIPE)
	{
		token = token->next;
		return (token);
	}
	if (token && token->type > 1)
		token = redirection(token, cmd);
	return (token);
}

t_token *make_av(t_token *token, t_cmd *cmd, t_data *data)
{
	int i;
	t_token *tmp;


	tmp = token;
	cmd_init(cmd);
	token = count_arg(token, cmd, data);
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
		tmp = make_av(tmp, &data->cmds[i], data);
		i++;
	}
	return (0);
}