#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*(dup);
	size_t	i;
	size_t	len;
	
	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int main()
{
	char str[] = "rima hanna kharrafit";
	char *dup = ft_strdup(str);
	printf("dup: %s\n", dup);

	char *dup1 = strdup(str);
	printf("dup1: %s\n", dup1);
	 
	return 0;
}*/
