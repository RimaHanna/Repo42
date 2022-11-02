#include <stdio.h>
char *ft_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char dest[] = "rima";
	char src[] = "hanna";
	char *ret = ft_strcat(dest, src);
	printf("%s\n", ret);
	return 0;
}
