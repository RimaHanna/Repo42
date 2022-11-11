
int ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strrchr(const char *s, int c)
{
	int len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return (char *)&s[len];
		len--;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "rima";
	char c = 'm';
	char *dest = ft_strrchr(str, c);
	printf("%s\n", dest);
	char *test = strrchr(str, c);
	printf("%s\n", test);
	return 0;
}

