#include <stdio.h>
int ft_str_is_printable(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (32 <= str[i] && str[i] <= 126)
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	char str[] = "kfj";
	int ret = ft_str_is_printable(str);
	printf("%d\n", ret);
	return 0;
}
