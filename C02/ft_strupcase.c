#include <stdio.h>
int ft_is_lower_case(char c)
{
	return ('a' <= c && c <= 'z');
}


char *ft_strupcase(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (ft_is_lower_case(str[i]))
			str[i] = str[i] - 32;
		i++;
	}
	
	return str;
}

int main()
{
	char str[] = "ASdsjfh";
	char *ret = ft_strupcase(str);
	printf("%s\n", ret);
	return 0;
}
