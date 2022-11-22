#include "libft.h"
#include <unistd.h>

void ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
int main()
{
	char *str = "rima hanna";
	ft_putendl_fd(str, 2);
	return 0;
}
*/
