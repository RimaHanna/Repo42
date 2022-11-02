#include <stdio.h>
char *ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;
	unsigned int j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	while (j < n)
	{
		dest [i] = '\0';
		j++;
	}
	return dest;
}

int main()
{
	char dest[10] = "rima";
	char src[] = "ha";
	unsigned int n = 10;
	char *ret = ft_strncat(dest, src, n);
	printf("%s\n", ret);
	return 0;
}
