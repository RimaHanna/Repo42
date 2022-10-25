#include <stdio.h>
int ft_is_uper_case(char c)
{
	return ('A' <= c && c <= 'Z');
}


char *ft_strlowcase(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (ft_is_uper_case(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	
	return str;
}

int main()
{
	char str[] = "ASdsjfh";
	char *ret = ft_strlowcase(str);
	printf("%s\n", ret);
	return 0;
}
