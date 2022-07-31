#include "../../01_include/libft.h"

int	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}