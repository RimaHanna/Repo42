# include <stdio.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
	{
		i++;
	}
	return s1[i] - s2[i];
}

int main()
{
	char s1[] = "abca";
	char s2[] = "abcb";
	unsigned int n = 4;
	int ret = ft_strncmp(s1, s2, n);
	printf("%d\n", ret);
	return 0;
}
