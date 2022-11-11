int ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32;
	return (c);
}

#include <stdio.h>
int main()
{
	char r = 'A';
	int ret = ft_toupper(r);
	printf("%d", ret);
	return 0;
}

