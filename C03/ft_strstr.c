char *ft_strFind(char *s1, char *toFind)
{
	int i, j;
	i = 0;
	while(s1[i])
	{
		j = 0;
		while (toFind[j] && s1[i + j])
		{
			if (s1[i + j] != toFind[j])
				break; 
			j++;
		}
		if ((j > 0) && (toFind[j] == '\0'))
			return (toFind);
		i++;
	}
	return 0;
}


#include <stdio.h>
int main()
{
	char s1[] = "rimahanna";
	char toFind[] = "maha";
	char *ret = ft_strFind(s1, toFind);
	printf("%s", ret);
return 0;
}

