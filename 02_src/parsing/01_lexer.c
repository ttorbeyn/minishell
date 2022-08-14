#include "../../01_include/minishell.h"

//int	double_quote_checker(char *str)
//{
//	int i;
//
//	i = 0;
//	while (str[i] != '"')
//
//}


//int is_cmd(char *cmd)
//{
//	int i;
//
//	char *builtin[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
//	printf("%s", builtin[0]);
//	i = 0;
//	while (builtin[i])
//	{
//		ft_strchr()
//		i++;
//	}
//	return (0);
//}

//char	**split_quotes(t_data *data)
//{
//	char **tmp;
//	int	i;
//	int j;
//	int x;
//
////	i = 0;
////	printf("%s\n", data->line);
//	x = 0;
//	while (data->line[i])
//	{
//		j = 0;
//		while (data->line[i] != '\'' && data->line[i] != '\"')
//			j++;
//		tmp[x++] = ft_strndup(data->line, j);
//		if (data->line[i] == '\'')
//		{
//			i++;
//			while (data->line[i] =! '\'' && data->line[i])
//				i++;
//		}
//		else if (data->line[i] == '\"')
//
//	}
//	tmp = ft_split(data->line, '\"');
////	while (data->line[i])
////	{
////		i++;
////	}
//	return (tmp);
//}

//int tokenizer(char **line, t_token *token)
//{
//	int i;
//
//	i = 0;
//	(void)token;
////	while (line[i])
////	{
////		if (is_cmd(line[i]))
////	}
//	return(i);
//}



//int	lex(t_data *data)
//{
//	int	i;
////	t_cmd cmd;
//	char **word;
//	t_quoted quoted;
//	int len;
////	t_token	token;
//
////	i = 0;
////	word = split_quotes(data);
////	while (data->line[i])
////	{
////		while (ft_isspace(data->line[i]))
////			i++;
////		word = ft_split(data->line, ' ');
////		tokenizer(word, &token);
////	}
//	i = 0;
//	while (data->line[i])
//	{
//		len = 0;
//		while (!check_quotes(data, data->line[i]) && data->line[i])
//		{
//			quoted.quoted = 0;
//			len++;
//			quoted.content = ft_strjoin(quoted.content, data->line[i])
//			i++;
//		}
//	}
//	i = 0;
//	while (word[i])
//	{
//		printf("%s\n", word[i]);
//		i++;
//	}
//	return (0);
//}

//char *ft_strtok()

//char **tokenize(char *str)
//{
//	int	i;
//	int	x;
//	int len;
//	char **tmp;
//
//	i = 0;
//	x = 0;
//	while (str[i])
//	{
//		tmp = malloc(x + 1);
//		len = 0;
//		while (ft_strchr(" |><", str[i]))
//		{
//			tmp[x] = malloc(len + 1);
//			tmp[x] = ft_strndup(&str[i], len);
//			len++;
//			i++;
//		}
//		x++;
//	}
//	return (tmp);
//}

int	lex(t_data *data)
{
	t_list *token;
//	t_list *tmp;
//	int i;

//	i = 0;
//	token = tokenize(data->line);
	token = ft_strtok(data->line);
	while (token)
	{
		printf("content : %s\n", (char*)token->content);
		token = token->next;
	}
	return (0);
}