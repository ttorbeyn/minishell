#include "../../01_include/minishell.h"

void	print_lst(t_list **env)
{
	t_list *first;

	first = *env;
	int len = ft_lstsize(env);
	int i = 0;
	while (i < len)
	{
		printf("%p\n", first->content);
		first = first->next;
		i++;
	}
}