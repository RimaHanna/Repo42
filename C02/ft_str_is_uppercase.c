#include <stdio.h> 
int ft_str_is_lowercase(char *str)
{
	int i = 0;
	while(str[i])
	{	
		if (!('A'<= str[i] && str[i] <= 'Z'))
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	char str[] = "SDFKJ";
	int ret = ft_str_is_lowercase(str);
	printf("%d\n", ret);
	return 0;


}
