#include <stdio.h> 
int ft_str_is_lowercase(char *str)
{
	int i = 0;
	while(str[i])
	{	
		if (!('a'<= str[i] && str[i] <= 'z'))
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	char str[] = "dsisj";
	int ret = ft_str_is_lowercase(str);
	printf("%d\n", ret);
	return 0;


}
