#include <strings.h>
void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return;
	size_t i;

	i = 0;
	unsigned char *str;
	str = (unsigned char *)s;
	while (str[i] && i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
int main()
{
	char str[] = "rima hanna";
	int i = 5;
	ft_bzero(str, i);
	printf("%s", str);
	return 0;
}
*/
