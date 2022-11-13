#include <stddef.h>
char *ft_strnstr(const char *s1, const char *toFind, size_t len)
{
	int i, j;
	i = 0;
	if (*toFind == 0)
		return ((char *)s1);
	while(s1[i])
	{
		j = 0;
		while (toFind[j] && s1[i + j] && j < len)
		{
			if (s1[i + j] != toFind[j])
				break; 
			j++;
		}
		if ((j > 0) && (toFind[j] == '\0'))
			return ((char *)s1 + i);
		i++;
	}
	return 0;
}


#include <stdio.h>
int main()
{
	char s1[] = "rimahanna";
	char toFind[] = "moh";
	int n = 3;
	char *ret = ft_strnstr(s1, toFind, n);
	printf("%s", ret);
	return 0;
}

