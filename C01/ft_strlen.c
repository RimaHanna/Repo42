#include <stdio.h>
int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{	
		i++;	
	}
	return i;
}

int main()
{
	char str[] = "eat shit";
	int ret = ft_strlen(str);
	printf("the tall of the string is %d\n", ret);
	return 0;
}
