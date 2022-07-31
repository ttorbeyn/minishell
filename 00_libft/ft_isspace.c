#include "../01_include/libft.h"

int	ft_isspace(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' || str == '\v'
		   || str == '\f' || str == '\r')
		return (1);
	return (0);
}
