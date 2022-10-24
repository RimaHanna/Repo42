#include <stdio.h>
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		printf("dest[%d]: %c (%d)\n", i, dest[i], dest[i]);
		i++;
	}
	dest[i] = '\0';
	i++;
	while (i < n)
	{
		dest[i] = '\0';
		printf("dest[%d]: (%d)\n", i, dest[i]);
		i++;
	}
	return dest;
}

int main(int argc, char **argv)
{
	(void) argc;
	char *dest;
	char des[15];
	dest = ft_strncpy(des, argv[1], 10);
	printf("%s\n", dest);
	printf("%d\n", dest[10]);
	return 0;

}
