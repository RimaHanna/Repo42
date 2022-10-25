#include <stdio.h>
int ft_str_is_numeric(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return 0;
		i++;
	}		
	return 1;
}

int main()
{
	char str[] = "dsf654";
	int ret = ft_str_is_numeric(str);
	printf("%d\n", ret);
	return 0;
}
