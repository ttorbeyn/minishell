#include "../../01_include/libft.h"

void	ft_panic(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}