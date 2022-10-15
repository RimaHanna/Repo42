#include <unistd.h>
void ft_putstr(char *str)
{
	int i = 0;
	while(str[i])
	{	
		write(1, &str[i], 1);
		i++;	
	}
	write(1, "\n", 1);
}

int main()
{
	char str[] = "eat shit";
	ft_putstr(str);
	return 0;
}
