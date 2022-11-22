#include "libft.h"
#include <unistd.h>
/*parameter 1 is the output file
param 2 is the execution
param 3 is the out */


void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
	char c = 'a';
	ft_putchar_fd(c, 1);
	return 0;
}*/
