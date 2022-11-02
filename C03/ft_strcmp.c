#include <stdio.h>
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return s1[i] - s2[i];
}

int main(int argc, char **argv)
{
	int ret = ft_strcmp(argv[1], argv[2]);
	printf("valeur de s1 - s2 est %d", ret);
	return 0;
}
